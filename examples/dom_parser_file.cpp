#include <libxmlmm/libxmlmm.h>

int main(int argc, char* argv[])
{
  xmlmm::DomParser parser;
  xmlmm::Document* doc = parser.parse_file("test.xml");

  delete doc;

  return 0;
}