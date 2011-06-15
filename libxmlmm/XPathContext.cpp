#include "XPathContext.h"

#include "libxmlmm/Document.h"
#include "libxmlmm/nodes/Node.h"
#include "libxmlmm/exceptions.h"

#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>

#include <boost/shared_ptr.hpp>

namespace xmlmm
{

  // TODO: Fix
  XPathContext::XPathContext(Document* doc) : m_cobj(xmlXPathNewContext(static_cast<_xmlDoc*>(*doc)))
  {
  }

  XPathContext::~XPathContext()
  {
    if (m_cobj != NULL)
    {
      xmlXPathFreeContext(m_cobj);
      m_cobj = NULL;
    }
  }

  void XPathContext::register_namespace(const std::string& prefix, const std::string& ns_uri)
  {
    if (0 != xmlXPathRegisterNs(m_cobj, 
      reinterpret_cast<const xmlChar*>(prefix.c_str()), 
      reinterpret_cast<const xmlChar*>(ns_uri.c_str())))
    {
      throw exception("xmlXPathRegisterNs returned -1");
    }
  }

  void XPathContext::unregister_namespace(const std::string& prefix)
  {
    if (0 != xmlXPathRegisterNs(m_cobj,
      reinterpret_cast<const xmlChar*>(prefix.c_str()), NULL))
    {
      throw exception("xmlXPathRegisterNs returned -1");
    }
  }

  bool XPathContext::is_namespace_registered(const std::string& prefix)
  {
    if (NULL != xmlXPathNsLookup(m_cobj, reinterpret_cast<const xmlChar*>(prefix.c_str())))
    {
      return true;
    }
    return false;
  }

  std::string XPathContext::lookup_namespace(const std::string& prefix)
  {
    const xmlChar* ns = xmlXPathNsLookup(m_cobj, reinterpret_cast<const xmlChar*>(prefix.c_str()));
    if (ns == NULL)
    {
      throw NoSuchNamespacePrefix(prefix);
    }

    return std::string(reinterpret_cast<const char*>(ns));
  }

  Node* XPathContext::find(const std::string& xpath, const Node* context)
  {
    if (context)
    {
      m_cobj->node = *const_cast<Node*>(context);
    }
    else
    {
      m_cobj->node = *(reinterpret_cast<Document*>(m_cobj->doc->_private)->get_root_element());
    }

    boost::shared_ptr<xmlXPathObject> result(
      xmlXPathEval(reinterpret_cast<const xmlChar*>(xpath.c_str()), m_cobj),
      xmlXPathFreeObject);

    if (result->type != XPATH_NODESET)
    {
      return NULL;
    }

    if (result->nodesetval->nodeNr <= 0)
    {
      return NULL;
    }

    return reinterpret_cast<Node*>(result->nodesetval->nodeTab[0]->_private);
  }

  XPathContext::NodeSet_t XPathContext::find_nodes(const std::string& xpath, const Node* context)
  {
    m_cobj->node = *const_cast<Node*>(context);

    boost::shared_ptr<xmlXPathObject> result(
      xmlXPathEval(reinterpret_cast<const xmlChar*>(xpath.c_str()), m_cobj),
      xmlXPathFreeObject);

    if (result->type != XPATH_NODESET)
    {
      return NodeSet_t();
    }

    NodeSet_t result_nodes(result->nodesetval->nodeNr);
    for (int i = 0; i < result->nodesetval->nodeNr; ++i)
    {
      result_nodes.push_back(reinterpret_cast<Node*>(result->nodesetval->nodeTab[i]->_private));
    }

    return result_nodes;
  }
} // namespace xmlmm