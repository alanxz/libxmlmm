#ifndef _LIBXMLMM_NONCOPYABLE_H_INCLUDED_
#define _LIBXMLMM_NONCOPYABLE_H_INCLUDED_

#include "libxmlmm/defines.h"

namespace xmlmm
{
  class LIBXMLMM_EXPORT Noncopyable
  {
  protected:
    Noncopyable() {}
    virtual ~Noncopyable() {}

  private:
    Noncopyable(const Noncopyable&);
    Noncopyable& operator=(const Noncopyable&);
  };
}

#endif // _LIBXMLMM_NONCOPYABLE_H_INCLUDED_