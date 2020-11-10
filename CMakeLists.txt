cmake_minimum_required(VERSION 3.18.4)

project(albion)
set(ALBI_DIR src)
set(ALBI_SRC ${ALBI_DIR}/main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${ALBI_SRC})
set_property(TARGET albion PROPERTY C_STANDARD 17)
set_property(TARGET albion PROPERTY C_STANDARD_REQUIRED ON)