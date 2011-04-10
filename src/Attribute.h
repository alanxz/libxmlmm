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

#ifndef _LIBXMLMM_ATTRIBUTE_H_INCLUDED_
#define _LIBXMLMM_ATTRIBUTE_H_INCLUDED_
#pragma once

#include <string>

#include "Node.h"

namespace xml
{
    /**
     * XML Attribtue Node Wrapper
     **/    
    class Attribute : public Node
    {
    public:
        /**
         * Construct Wrapper
         **/
        explicit Attribute(xmlNode* const cobj);
        
        /**
         * Get the value of this node.  Empty if not found.
         **/         
        virtual std::string get_value() const;
        
        /**
         * Set the value.
         **/
        void set_value(const std::string& value);
    };    
}
#endif // _LIBXMLMM_ATTRIBUTE_H_INCLUDED_
