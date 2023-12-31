enable_testing()

set(TEST_LIB test_lib)

add_library(${TEST_LIB} INTERFACE)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

target_link_libraries(
    ${TEST_LIB} INTERFACE
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY} ${ALGO_LIB}
)

function(add_algo_lib_test TEST_NAME TEST_SOURCE)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_link_libraries(${TEST_NAME} ${TEST_LIB})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME} WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endfunction()

set(ALGORITHM test_algorithm)
add_algo_lib_test(test_integer ${ALGORITHM}/test_integer.cpp)
add_algo_lib_test(test_sort ${ALGORITHM}/test_sort.cpp)

set(UTILS test_utils)
add_algo_lib_test(test_compare ${UTILS}/test_compare.cpp)
add_algo_lib_test(test_output ${UTILS}/test_output.cpp)