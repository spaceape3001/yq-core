################################################################################
##
##  YOUR QUILL
##
################################################################################

add_library(yq_xml SHARED
    xml/XmlFile.cpp
    xml/XmlObject.cpp
    xml/XmlUtils.cpp
)

target_link_libraries(yq_xml PUBLIC
    yq_core yq_file
    RapidXml
)

LinkTest(yq_xml)

