cmake_minimum_required(VERSION 3.18.4)

enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/include)

set(TEST_CASES
  DummyTest
  GTestCheckTest
  BasicPositionalArgumentParsingChecksTest
)

foreach(_test_case ${TEST_CASES})
  add_executable(${_test_case} ${_test_case}.cpp)
  add_custom_command(TARGET ${_test_case} POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     "${CMAKE_CURRENT_BINARY_DIR}/../lib${PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX}"
                     $<TARGET_FILE_DIR:${_test_case}>)
  target_link_libraries(${_test_case} ${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES})
  GTEST_ADD_TESTS(${_test_case} "${_test_case}Args" ${_test_case}.cpp)
  set_property(TARGET ${_test_case} PROPERTY CXX_STANDARD 17)
  set_property(TARGET ${_test_case} PROPERTY CXX_STANDARD_REQUIRED ON)
endforeach()

# Adding tests is done outside the above loop,
# as each test will need different arguments.

##################################################################################################
# Dont forget its:  add_test(<test name (globally unique) > <exe name> <argument1> <argument2>
##################################################################################################

add_test(DummyTest ${RUNTIME_OUTPUT_DIRECTORY}/DummyTest)
# add_test(GTestCheckTest ${RUNTIME_OUTPUT_DIRECTORY}/GTestCheckTest)