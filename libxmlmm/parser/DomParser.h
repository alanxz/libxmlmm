#ifndef _LIBXMLMM_DOMPARSER_H_INCLUDED_
#define _LIBXMLMM_DOMPARSER_H_INCLUDED_

#include "libxmlmm/Noncopyable.h"

#include <iosfwd>
#include <string>

namespace xmlmm
{

  class Document;

  class DomParser : Noncopyable
  {
  public:
    DomParser();
    virtual ~DomParser();

    Document* parse_file(const std::string& filename);

    Document* parse_string(const std::string& xml);

    Document* parse_stream(std::istream& xml);

    Document* parse_raw_memory(const char* buffer, int len);

  };
}
#endif // _LIBXMLMM_DOMPARSER_H_INCLUDED_