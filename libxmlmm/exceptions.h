//
// libxmlmmm
// Copyright 2008 - 2009 Sean Farell
//
// This file is part of libqgl.
//
// libxmlmmm is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libxmlmmm is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with libxmlmmm. If not, see <http://www.gnu.org/licenses/>.
//

#ifndef _LIBXMLMM_EXCEPTIONS_H_
#define _LIBXMLMM_EXCEPTIONS_H_

#include "libxmlmm/defines.h"

#include <string>
#include <stdexcept>

#ifdef _MSC_VER
# pragma warning ( push )
# pragma warning ( disable: 4275 )
#endif 

namespace xmlmm
{
  struct LIBXMLMM_EXPORT exception : std::runtime_error
  {
    explicit exception(const std::string &what)
      : runtime_error("xmlmm: " + what) {}
    ~exception() throw() {}
  };

  struct LIBXMLMM_EXPORT NoRootElement : exception
  {
    NoRootElement() : exception("No root element") {}
  };

  struct LIBXMLMM_EXPORT EmptyDocument : exception
  {
    EmptyDocument() : exception("Document is empty") {}
  };

  struct LIBXMLMM_EXPORT InvalidXPath : exception
  {
    explicit InvalidXPath(const std::string &xpath)
      : exception("Invalid XPath: " + xpath) {}
    ~InvalidXPath() throw() {}
  };

  struct LIBXMLMM_EXPORT NoSuchAttribute : exception
  {
    NoSuchAttribute(const std::string &attribute,
      const std::string &nodeName)
      : exception("There is no attribute '" + attribute +
      "' on the element '" + nodeName + "'.") {}
    ~NoSuchAttribute() throw() {}
  };

  struct LIBXMLMM_EXPORT ValidityError : exception
  {
    explicit ValidityError(const std::string& message)
      : exception("Document is not valid: " + message) {}
    ~ValidityError() throw() {}
  };
}

#ifdef _MSC_VER
# pragma warning ( pop )
#endif

#endif
