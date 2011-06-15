#include <libxmlmm/libxmlmm.h>

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  xmlmm::DomParser parser;
  xmlmm::Document* doc = parser.parse_file("xpath_test.xml");

  xmlmm::XPathContext xpath(doc);

  xpath.register_namespace("ns", "http://xpathrocks.com/example");

  xmlmm::Node* node = xpath.find("/telephone/ns:type", doc->get_root_element());

  if (!node)
  {
    std::cerr << "Failed.\n";
  }
  else
  {
    std::cerr << "Success, value: " << node->get_value() << std::endl;
  }

  return 0;
}