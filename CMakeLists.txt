cmake_minimum_required(VERSION 3.18.4)

project(albion)
set(ALBI_DIR src/lib)
set(ALBI_SRC ${ALBI_DIR}/dummy.cpp)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(Testing)

include_directories(${PROJECT_SOURCE_DIR}/include)

# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

add_library(${PROJECT_NAME} SHARED ${ALBI_SRC})
set_property(TARGET albion PROPERTY C_STANDARD 17)
set_property(TARGET albion PROPERTY C_STANDARD_REQUIRED ON)