#include <libxmlmm/libxmlmm.h>

#include <iostream>

int main(int argc, char* argv[])
{
  xmlmm::DomParser parser;
  xmlmm::Document* doc = parser.parse_file("test.xml");

  std::cout << doc->has_root_element() << std::endl;
  std::cout << *doc << std::endl;

  xmlmm::Element* root = doc->get_root_element();

  std::cout << root->get_name() << std::endl;

  std::cout << root->query_string("buttons/@doesnotexist") << std::endl;

  delete doc;

  return 0;
}