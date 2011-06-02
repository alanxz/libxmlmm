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

#ifndef _LIBXMLMM_DOCUMENT_H_INCLUDED_
#define _LIBXMLMM_DOCUMENT_H_INCLUDED_

#include "libxmlmm/defines.h"
#include "libxmlmm/nodes/Element.h"
#include "libxmlmm/LibXmlSentry.h"

#include <string>
#include <iosfwd>
#include <libxml/tree.h>

namespace xmlmm
{
    /**
     * XML DOM Document
     *
     * This class is the root class for the XML DOM. 
     *
     * @todo Add read and write from file.      
     **/    
    class LIBXMLMM_EXPORT Document
    {
    public:    
        /** 
         * Default Constructor
         **/
        Document();
        
        /** 
         * Construct and populate from the specified xml string.
         *
         * @exception exception Throws exception if the xml is invalid.
         **/
        explicit Document(const std::string &xml);

        /**
         * Destructor
         **/
        ~Document();
        
        /**
         * Check if the document has a root element.
         *
         * @return true if the document has a root element.
         **/
        bool has_root_element() const;
        
        /**
         * Get the root element.
         *
         * @return The root element.
         *
         * @exception NoRootElement Throws NoRootElement if the document has
         * no root element.
         *
         * @{
         **/
        Element* get_root_element();
        const Element* get_root_element() const;
        /** @} **/        
    
        /**
         * Create the root element of a document.
         *
         * @param name The name of the root node.
         * @return The root element.
         *
         * @exception exception Throws exception if the document already
         * has a root element.
         **/
        Element* create_root_element(const std::string& name);
        
        /**
         * Write document to string.
         **/
        std::string write_to_string() const;
        
        /**
         * Write document to stream.
         **/
        void write_to_stream(std::ostream& os) const;
        
        /**
         * Write document to file.
         **/
        void write_to_file(const std::string& file) const;
        
        /**
         * Read document from string.
         *
         * @todo Add error handling.
         **/
        void read_from_string(const std::string& xml);
        
        /**
         * Read document from stream.
         *
         * @todo Add error handling.
         **/
        void read_from_stream(std::istream& is);
        
        /**
         * Read the XML document from file.
         **/
        void read_from_file(const std::string& file);
        
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
         * Find a given set of nodes.
         *
         * @param xpath the xpath
         * @return the nodes found
         *
         * @{
         **/
        std::vector<Node*> find_nodes(const std::string& xpath);
        std::vector<const Node*> find_nodes(const std::string& xpath) const;
        /** @} **/
        
        /**
         * Find a given element.
         *
         * @param xpath the xpath relative to this element
         * @return the element found
         *
         * @{
         **/
        Element* find_element(const std::string& xpath);
        const Element* find_element(const std::string& xpath) const;
        /** @} **/
        
        /**
         * Find a given set of elements.
         *
         * @param xpath the xpath relative to this element
         * @return the elements found
         *
         * @{
         **/
        std::vector<Element*> find_elements(const std::string& xpath);
        std::vector<const Element*> find_elements(const std::string& xpath) const;
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
        
    private:
        xmlDoc* cobj;
        
        LibXmlSentry libxml_sentry;
        
        Document(const Document&);
        Document& operator = (const Document&);
    };   
    
    /** 
     * Stream insert operator.
     **/
    LIBXMLMM_EXPORT std::ostream& operator << (std::ostream& os, const Document& doc);
    
    /** 
     * Stream extract operator.
     **/
    LIBXMLMM_EXPORT std::istream& operator >> (std::istream& is, Document& doc);
}
#endif // _LIBXMLMM_DOCUMENT_H_INCLUDED_
