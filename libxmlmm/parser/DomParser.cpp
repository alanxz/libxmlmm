#include "DomParser.h"

#include "libxmlmm/Document.h"
#include "libxmlmm/exceptions.h"
#include "libxmlmm/parser/IstreamParserAdapter.h"

#include <libxml/parser.h>
#include <libxml/parserInternals.h>
#include <libxml/tree.h>

#include <boost/shared_ptr.hpp>

#include <istream>

namespace xmlmm
{

  DomParser::DomParser() : m_validate(false), m_keepBlanks(true)
  {
  }

  DomParser::~DomParser()
  {
  }

  Document* DomParser::parse_file(const std::string& filename)
  {
    boost::shared_ptr<xmlParserCtxt> context(xmlCreateFileParserCtxt(filename.c_str()), xmlFreeParserCtxt);
    return parse_context(context.get());
  }

  Document* DomParser::parse_string(const std::string& xml)
  {
    return parse_raw_memory(xml.c_str(), xml.length());
  }

  Document* DomParser::parse_stream(std::istream& stream)
  {
    impl::IstreamParserAdapter adapter(stream);
    boost::shared_ptr<xmlParserCtxt> context(xmlCreateIOParserCtxt(
      NULL,
      NULL,
      &impl::IstreamParserAdapter::on_read,
      &impl::IstreamParserAdapter::on_close,
      &adapter,
      XML_CHAR_ENCODING_NONE), xmlFreeParserCtxt);

    return parse_context(context.get());
  }

  Document* DomParser::parse_raw_memory(const char* buffer, int length)
  {
    boost::shared_ptr<xmlParserCtxt> context(xmlCreateMemoryParserCtxt(buffer, length), xmlFreeParserCtxt);
    return parse_context(context.get());
  }

  Document* DomParser::parse_context(xmlParserCtxtPtr parse_context)
  {
    parse_context->validate = (m_validate ? 1 : 0);
    parse_context->keepBlanks = (m_keepBlanks ? 1 : 0);

    parse_context->vctxt.error = &on_error;
    parse_context->vctxt.warning = &on_warning;
    parse_context->_private = this;
    m_errors.clear();
    m_warnings.clear();

    xmlParseDocument(parse_context);

    if (parse_context->valid == 0)
    {
      throw ValidityError("Document not valid");
    }

    if (!m_errors.empty())
    {
      throw ValidityError(m_errors);
    }

    return new Document(parse_context->myDoc);
  }

  void DomParser::on_error(void* context, const char* msg, ...)
  {
    if (context == NULL)
    {
      return;
    }
    va_list args;
    va_start(args, msg);
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer)/sizeof(buffer[0]), msg, args);
    
    DomParser* parser = static_cast<DomParser*>(context);
    parser->add_error(buffer);
  }

  void DomParser::on_warning(void* context, const char* msg, ...)
  {
    if (context == NULL)
    {
      return;
    }
    va_list args;
    va_start(args, msg);
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer)/sizeof(buffer[0]), msg, args);
    
    DomParser* parser = static_cast<DomParser*>(context);
    parser->add_warning(buffer);
  }

  void DomParser::add_error(const std::string& err)
  {
    m_errors.append(err);
  }

  void DomParser::add_warning(const std::string& warn)
  {
    m_warnings.append(warn);
  }
} // namespace xmlmm