cmake_minimum_required(VERSION 3.18)   

project(cpp2023_test)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_CURRENT_SOURCE_DIR}/bin.relwithdbg)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True) 

find_package(imgui CONFIG REQUIRED)
find_package(OpenCV REQUIRED)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install" CACHE PATH "..." FORCE)
endif()

option(BUILD_WITH_CODEFORCES "Build prj.codeforces targets" off)

if (BUILD_WITH_CODEFORCES)
  add_subdirectory(prj.codeforces)
endif()

option(BUILD_ONLY_LIBRARY "Build only FileBrowser interface" off)

if (BUILD_ONLY_LIBRARY)
  add_subdirectory(prj.cw/libs)
else()
  add_subdirectory(prj.cw)
endif()