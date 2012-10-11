project(libhasso)
cmake_minimum_required(VERSION 2.8)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
#find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)


#include_directories(${SFML_INCLUDE_DIR})




#file(COPY "resources" DESTINATION ".")


add_subdirectory(src)
add_subdirectory(testapp)