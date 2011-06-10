#ifndef _LIBXMLMM_DOMPARSER_H_INCLUDED_
#define _LIBXMLMM_DOMPARSER_H_INCLUDED_

#include "libxmlmm/defines.h"
#include "libxmlmm/Noncopyable.h"
#include "libxmlmm/LibXmlSentry.h"

#include <iosfwd>
#include <string>
#include <cstdarg>

extern "C"
{
  struct _xmlParserCtxt;
}

namespace xmlmm
{

  class Document;

  class LIBXMLMM_EXPORT DomParser : Noncopyable
  {
  public:
    DomParser();
    virtual ~DomParser();

    Document* parse_file(const std::string& filename);

    Document* parse_string(const std::string& xml);

    Document* parse_stream(std::istream& xml);

    Document* parse_raw_memory(const char* buffer, int len);

  protected:
    static void on_error(void* context, const char* args, ...);
    static void on_warning(void* context, const char* args, ...);

    void add_error(const std::string& err);
    void add_warning(const std::string& warn);

    Document* parse_context(_xmlParserCtxt* context);

  private:
    bool m_validate;
    bool m_keepBlanks;
    std::string m_errors;
    std::string m_warnings;

    LibXmlSentry libxml_sentry;
  };
}
#endif // _LIBXMLMM_DOMPARSER_H_INCLUDED_