SET(libxmlmm_SRCS
	Document.h
	Document.cpp

	LibXmlSentry.h
	LibXmlSentry.cpp

	defines.h

	exceptions.h

	libxmlmm.h

	utils.h
	utils.cpp

	nodes/Attribute.h
	nodes/Attribute.cpp

	nodes/CData.h
	nodes/CData.cpp

	nodes/Comment.h
	nodes/Comment.cpp

	nodes/Content.h
	nodes/Content.cpp

	nodes/Element.h
	nodes/Element.cpp

	nodes/Node.h
	nodes/Node.hxx
	nodes/Node.cpp

	nodes/ProcessingInstruction.h
	nodes/ProcessingInstruction.cpp

	nodes/Text.h
	nodes/Text.cpp

	nodes/find_nodeset.h
	nodes/find_nodeset.cpp
)

INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

ADD_DEFINITIONS(-DBUILDING_LIBXMLMM ${LIBXML2_DEFINITIONS})

ADD_LIBRARY(xmlmm-shared SHARED ${libxmlmm_SRCS})
ADD_LIBRARY(xmlmm-static STATIC ${libxmlmm_SRCS})

SET_TARGET_PROPERTIES(xmlmm-shared PROPERTIES OUTPUT_NAME xmlmm)
SET_TARGET_PROPERTIES(xmlmm-static PROPERTIES OUTPUT_NAME xmlmm)

TARGET_LINK_LIBRARIES(xmlmm-shared ${LIBXML2_LIBRARIES})
