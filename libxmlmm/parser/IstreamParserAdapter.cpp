#include "IstreamParserAdapter.h"

#include <istream>

namespace xmlmm
{
namespace impl
{
  
  IstreamParserAdapter::IstreamParserAdapter(std::istream& stream) : m_stream(stream)
  {
  }

  IstreamParserAdapter::~IstreamParserAdapter()
  {
  }

  int IstreamParserAdapter::on_read(void* context, char* buffer, int length)
  {
    if (context != NULL)
    {
      IstreamParserAdapter* adapter = static_cast<IstreamParserAdapter*>(context);
      return adapter->do_read(buffer, length);
    }
    return -1;
  }

  int IstreamParserAdapter::on_close(void* context)
  {
    if (context != NULL)
    {
      IstreamParserAdapter* adapter = static_cast<IstreamParserAdapter*>(context);
      return adapter->do_close();
    }
    return -1;
  }

  int IstreamParserAdapter::do_read(char* buffer, int length)
  {
    return m_stream.readsome(buffer, length);
  }

  int IstreamParserAdapter::do_close()
  {
    return 0;
  }
} // namespace impl
} // namespace xmlmm