#ifndef _LIBXMLMM_ISTREAMPARSERADAPTER_H_INCLUDED_
#define _LIBXMLMM_ISTREAMPARSERADAPTER_H_INCLUDED_

#include "libxmlmm/Noncopyable.h"

#include <iosfwd>

namespace xmlmm
{
namespace impl
{
  class IstreamParserAdapter : xmlmm::Noncopyable
  {
  public:
    explicit IstreamParserAdapter(std::istream& stream);
    virtual ~IstreamParserAdapter();

    static int on_read(void* context, char* buffer, int length);
    static int on_close(void* context);

  protected:
    int do_read(char* buffer, int length);
    int do_close();

    std::istream& m_stream;
  };

}
}
#endif _LIBXMLMM_ISTREAMPARSERADAPTER_H_INCLUDED_