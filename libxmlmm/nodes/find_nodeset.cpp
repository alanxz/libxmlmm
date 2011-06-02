#include "find_nodeset.h"
#include "libxmlmm/exceptions.h"

#include <libxml/tree.h>
#include <libxml/xpath.h>

namespace xmlmm
{
namespace impl
{

  find_nodeset::find_nodeset(xmlNode *const cobj,
    const std::string &xpath,
    const xmlXPathObjectType type)
  {
    ctxt = xmlXPathNewContext(cobj->doc);
    ctxt->node = cobj;

    result = xmlXPathEval(reinterpret_cast<const xmlChar*>(xpath.c_str()), ctxt);
    if (!result)
    {
      xmlXPathFreeContext(ctxt);
      throw InvalidXPath(xpath);
    }

    if (type != XPATH_UNDEFINED && result->type != type)
    {
      xmlXPathFreeObject(result);
      xmlXPathFreeContext(ctxt);
      throw exception("Unsuported query.");
    }
  }

  //------------------------------------------------------------------------------

  find_nodeset::~find_nodeset()
  {
    xmlXPathFreeObject(result);
    xmlXPathFreeContext(ctxt);
  }

} // namespace impl
} // namespace xmlmm