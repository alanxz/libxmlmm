SET(libxmlmm_SRCS
	Attribute.h
	Attribute.cpp

	CData.h
	CData.cpp

	Comment.h
	Comment.cpp

	Content.h
	Content.cpp

	Document.h
	Document.cpp

	Element.h
	Element.cpp

	LibXmlSentry.h
	LibXmlSentry.cpp

	Node.h
	Node.cpp

	ProcessingInstruction.h
	ProcessingInstruction.cpp

	Text.h
	Text.cpp

	defines.h

	exceptions.h

	libxmlmm.h

	utils.h
	utils.cpp
)

INCLUDE_DIRECTORIES(${LIBXML2_INCLUDE_DIR})

ADD_DEFINITIONS(-DBUILDING_LIBXMLMM ${LIBXML2_DEFINITIONS})

ADD_LIBRARY(xmlmm-shared SHARED ${libxmlmm_SRCS})
ADD_LIBRARY(xmlmm-static STATIC ${libxmlmm_SRCS})

SET_TARGET_PROPERTIES(xmlmm-shared PROPERTIES OUTPUT_NAME xmlmm)
SET_TARGET_PROPERTIES(xmlmm-static PROPERTIES OUTPUT_NAME xmlmm)

TARGET_LINK_LIBRARIES(xmlmm-shared ${LIBXML2_LIBRARIES})
