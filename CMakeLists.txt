cmake_minimum_required(VERSION 3.18.4)

project(albion)
set(ALBI_DIR src/lib)
set(ALBI_SRC ${ALBI_DIR}/dummy.cpp)

enable_testing()

add_subdirectory(Testing)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} SHARED ${ALBI_SRC})
set_property(TARGET albion PROPERTY C_STANDARD 17)
set_property(TARGET albion PROPERTY C_STANDARD_REQUIRED ON)