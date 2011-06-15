#ifndef _XMLMM_XPATHCONTEXT_H_INCLUDED_
#define _XMLMM_XPATHCONTEXT_H_INCLUDED_

#include "libxmlmm/defines.h"
#include "libxmlmm/Noncopyable.h"

#include <string>
#include <vector>

extern "C"
{
  struct _xmlXPathContext;
}
namespace xmlmm
{
  class Document;
  class Node;

  class LIBXMLMM_EXPORT XPathContext : Noncopyable
  {
  public:
    typedef std::vector<Node*> NodeSet_t;

    explicit XPathContext(Document* context);
    virtual ~XPathContext();

    void register_namespace(const std::string& prefix, const std::string& namespace_uri);
    void unregister_namespace(const std::string& prefix);

    bool is_namespace_registered(const std::string& prefix);
    std::string lookup_namespace(const std::string& prefix);

    Node* find(const std::string& xpath, const Node* context = NULL);
    NodeSet_t find_nodes(const std::string& xpath, const Node* context = NULL);
    bool exists(const std::string& xpath, const Node* context = NULL);

    

  private:
    struct _xmlXPathContext* m_cobj;

  };
} // namespace xmlmm
#endif // _XMLMM_XPATHCONTEXT_H_INCLUDED_