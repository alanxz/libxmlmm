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

#ifndef _LIBXMLMM_CONTENT_H_INCLUDED_
#define _LIBXMLMM_CONTENT_H_INCLUDED_

#include "libxmlmm/nodes/Node.h"
#include "libxmlmm/defines.h"

#include <string>

namespace xmlmm
{
  /**
  * XML Text Node Wrapper
  **/    
  class LIBXMLMM_EXPORT Content : public Node
  {
  public:
    /**
    * Construct Wrapper
    **/
    explicit Content(_xmlNode* const cobj);

    /**
    * Get the value of this node.  Empty if not found.
    **/
    virtual std::string get_value() const;

    /**
    * Get the content of a content node.  Empty if none.
    * @deprecated Use get_value().
    **/
    std::string get_content() const
    { return this->get_value(); }

    /**
    * Set the content of a content node.
    **/
    void set_content(const std::string& value);

    /**
    * Check if a given note is a blank node.
    **/
    bool is_blank() const;        
  };    
}
#endif // _LIBXMLMM_CONTENT_H_INCLUDED_
