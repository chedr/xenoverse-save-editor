set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 2.8)
project(xenoverse)

################################################## Compiler Settings ###################################################

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wshadow -Weffc++ -pedantic -pipe -fnon-call-exceptions")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-mtune=native -DNDEBUG -O2 -fomit-frame-pointer")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-s")

################################################## Library Settings/Build ##############################################

# Static library
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include")
file(GLOB_RECURSE PROJECT_FILES_CXX "${PROJECT_SOURCE_DIR}/*.cpp")
add_library(xenoverse STATIC ${PROJECT_FILES_CXX})
target_include_directories(xenoverse PUBLIC "${PROJECT_INCLUDE_DIR}")

################################################## Executable Settings/Build ###########################################

# Test executable
set(TEST_SOURCE_DIR "test")
file(GLOB_RECURSE TEST_FILES_CXX "${TEST_SOURCE_DIR}/*.cpp")
add_executable(xenoverse-save-editor ${TEST_FILES_CXX})
target_link_libraries(xenoverse-save-editor xenoverse)
