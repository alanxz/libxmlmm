CONFIGURE_FILE(test.xml test.xml COPYONLY)
ADD_EXECUTABLE(dom_parser_file dom_parser_file.cpp test.xml)
TARGET_LINK_LIBRARIES(dom_parser_file xmlmm)

CONFIGURE_FILE(xpath_test.xml xpath_test.xml COPYONLY)
ADD_EXECUTABLE(xpath_test xpath_test.cpp xpath_test.xml)
TARGET_LINK_LIBRARIES(xpath_test xmlmm)
