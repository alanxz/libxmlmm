
#include "libxmlmm/nodes/find_nodeset.h"

#include <libxml/tree.h>

namespace xmlmm
{

template <typename NodeType_>
NodeType_ Node::find(const std::string &xpath) const {
  impl::find_nodeset search(cobj, xpath, XPATH_NODESET);
  xmlNodeSet *const nodeset = search;
  if (!nodeset || nodeset->nodeNr == 0)
  {
    return NULL;
  }
  return reinterpret_cast<NodeType_>(nodeset->nodeTab[0]->_private);
}

template <typename NodeType_>
std::vector<NodeType_> Node::find_all(const std::string &xpath) const {
  impl::find_nodeset search(cobj, xpath, XPATH_NODESET);
  xmlNodeSet *const nodeset = search;
  std::vector<NodeType_> nodes;
  if (nodeset != NULL)
  {
    for (int i = 0; i != nodeset->nodeNr; i++)
    {
      nodes.push_back(reinterpret_cast<NodeType_>(nodeset->nodeTab[i]->_private));
    }
  }
  return nodes;
}

} // namespace xmlmm