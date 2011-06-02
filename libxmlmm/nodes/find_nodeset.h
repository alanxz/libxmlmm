#ifndef FIND_NODESET_H_INCLUDED_
#define FIND_NODESET_H_INCLUDED_

#include <libxml/tree.h>
#include <libxml/xpath.h>

#include <string>

namespace xmlmm
{
namespace impl
{

  // Helper object to keep our xpath search context.
  struct find_nodeset {
    find_nodeset(xmlNode *const cobj,
      const std::string &xpath,
      const xmlXPathObjectType type = XPATH_UNDEFINED);
    ~find_nodeset();

    operator xmlXPathObject *()
    { return result; }

    operator xmlNodeSet *()
    { return result->nodesetval; }

  private:
    xmlXPathContext* ctxt;
    xmlXPathObject* result;
  };

} // namespace impl
} // namespace xmlmm

#endif //FIND_NODESET_H_INCLUDED_