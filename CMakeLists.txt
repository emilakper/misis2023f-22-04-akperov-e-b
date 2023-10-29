cmake_minimum_required(VERSION 3.18)   

project(cpp2023_test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "..." FORCE)
endif()

find_package(imgui CONFIG REQUIRED)
find_package(OpenCV REQUIRED)
find_package(glad CONFIG REQUIRED)

add_subdirectory(prj.cw)
add_subdirectory(prj.codeforces)