cmake_minimum_required(VERSION 2.8.12)

project(OnCrashHandler)

set(CMAKE_C_STANDARD 99)

aux_source_directory(. DIR_LIB_SRCS)
include_directories(${CMAKE_SOURCE_DIR})

add_library(${PROJECT_NAME} STATIC ${DIR_LIB_SRCS})
# add_library(${PROJECT_NAME} SHARED ${DIR_LIB_SRCS})

# add_subdirectory(test)

