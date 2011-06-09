#include "DomParser.h"

#include "libxmlmm/Document.h"

#include <libxml/parser.h>

#include <istream>

namespace xmlmm
{

  DomParser::DomParser()
  {
  }

  DomParser::~DomParser()
  {
  }

  Document* DomParser::parse_file(const std::string& filename)
  {
    xmlDocPtr doc = xmlReadFile(
      filename.c_str(),
      NULL, // detect encoding
      0); // Use default

    return new Document(doc);
  }

  Document* DomParser::parse_string(const std::string& xml)
  {
    return parse_raw_memory(xml.c_str(), xml.length());
  }

  Document* DomParser::parse_stream(std::istream& stream)
  {
  }

  Document* DomParser::parse_raw_memory(const char* buffer, int length)
  {
    xmlDocPtr doc = xmlReadMemory(buffer, length, 
      NULL, // No URI
      NULL, // detect encoding
      0); // Use default options

    return new Document(doc);
  }

}