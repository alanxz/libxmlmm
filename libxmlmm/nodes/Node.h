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

#ifndef _LIBXMLMM_NODE_H_INCLUDED_
#define _LIBXMLMM_NODE_H_INCLUDED_

#include "libxmlmm/defines.h"
#include "libxmlmm/Noncopyable.h"
#include "libxmlmm/utils.h"

#include <string>
#include <vector>

extern "C"
{
  struct _xmlNode;
}

namespace xmlmm
{
  class Element;

  /**
  * XML DOM Node
  *
  * The Node class is the base class for all DOM elements (except Document). 
  * It is effectively a wrapper for xmlNode.
  **/    
  class LIBXMLMM_EXPORT Node : Noncopyable
  {
  protected:
    /**
    * Construct Wrapper
    *
    * @param cobj The xmlNode object to wrap.
    **/
    explicit Node(_xmlNode* const cobj);

  public:
    /**
    * Destructor
    **/
    virtual ~Node();       

    /**
    * Get the node's path
    **/
    std::string get_path() const;

    /**
    * Get the node's parent.
    *
    * @return The node's parent.
    *
    * @throw exception If the node has no parent node.
    *
    * @note It is safe to assume that all nodes have a parent. If this
    * is not the case something is really broken.
    **/
    Element* get_parent(); 

    /**
    * Get the node's parent.
    *
    * @return The node's parent.
    *
    * @throw exception If the node has no parent node, exception is
    * raised.
    *
    * @note It is safe to assume that all nodes have a parent. If this
    * is not the case something is really broken.
    **/
    const Element* get_parent() const;  

    /**
    * Find a given node.
    *
    * @param xpath the xpath relative to this node
    * @return the node found
    *
    * @{
    **/
    Node* find_node(const std::string& xpath);
    const Node* find_node(const std::string& xpath) const;
    /** @} **/

    /**
    * Find a set of nodes.
    *
    * @param xpath the xpath relative to this node
    * @return the nodes found
    *
    * @{
    **/
    std::vector<Node*> find_nodes(const std::string& xpath);
    std::vector<const Node*> find_nodes(const std::string& xpath) const;
    /** @} **/

    /**
    * Query a value.
    *
    * @param xpath the xpath
    * @return the value
    *
    * @{
    **/
    std::string query_string(const std::string& xpath) const;
    double query_number(const std::string& xpath) const;
    /** @} **/

    /**
    * Get the value of this node.  Empty if not found.
    **/
    virtual std::string get_value() const = 0;

    operator _xmlNode* ();
    operator const _xmlNode* () const;

  protected:    
    /** The wrapped xmlNode object. **/
    _xmlNode* cobj;

    template <typename NodeType_>
    NodeType_ find(const std::string &xpath) const;

    template <typename NodeType_>
    std::vector<NodeType_> find_all(const std::string &xpath) const;

  private:
  };    

} // namespace xmlmm

#ifdef BUILDING_LIBXMLMM
# include "Node.hxx"
#endif

#endif // _LIBXMLMM_NODE_H_INCLUDED_
