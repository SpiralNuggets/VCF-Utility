cmake_minimum_required(VERSION 3.0.0)
project(vcardutil VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(include)
add_executable(vcardutil main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_library(vcardlib STATIC
        src/vcard.cpp
        src/json_io.cpp
        src/text_io.cpp
        src/xml_io.cpp
        src/utils.cpp )

target_include_directories(vcardutil PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(vcardutil vcardlib)

include(CPack)