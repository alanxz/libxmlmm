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

#ifndef _LIBXMLMM_TEXT_H_INCLUDED_
#define _LIBXMLMM_TEXT_H_INCLUDED_

#include "libxmlmm/defines.h"
#include "libxmlmm/nodes/Content.h"


namespace xmlmm
{
  /**
  * XML Text Node Wrapper
  **/    
  class LIBXMLMM_EXPORT Text : public Content
  {
  public:
    /**
    * Construct Wrapper
    **/
    explicit Text(_xmlNode* const cobj);

  };    
}
#endif // _LIBXMLMM_TEXT_H_INCLUDED_
