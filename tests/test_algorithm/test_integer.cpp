#define BOOST_TEST_MODULE test_vector_nums
#include <boost/test/unit_test.hpp>

#include "algo_lib/algorithm/integer.hpp"
#include "algo_lib/utils/compare.hpp"

BOOST_AUTO_TEST_SUITE(test_vector_nums)

BOOST_AUTO_TEST_CASE(test_to_string_0)
{
    algo_lib::Integer integer = {{2, 5, 3}};
    BOOST_TEST_CHECK(integer.toString() == "253");
}

BOOST_AUTO_TEST_CASE(test_to_string_1)
{
    algo_lib::Integer integer;
    BOOST_TEST_CHECK(integer.toString() == "0");
}

BOOST_AUTO_TEST_CASE(test_add_0)
{
    algo_lib::Integer integer0 = {{1, 9, 3, 2, 6}};
    algo_lib::Integer integer1 = {{5, 5}};

    algo_lib::Integer result = integer0 + integer1;
    algo_lib::Integer correct_result = {{1, 9, 3, 8, 1}};

    BOOST_TEST_CHECK((result == correct_result)); 
}

BOOST_AUTO_TEST_CASE(test_add_1)
{
    algo_lib::Integer integer0 = {{9, 9, 9}};
    algo_lib::Integer integer1 = {{1}};

    algo_lib::Integer result = integer0 + integer1;
    algo_lib::Integer correct_result = {{1, 0 , 0, 0}};

    BOOST_TEST_CHECK((result == correct_result)); 
}

BOOST_AUTO_TEST_CASE(test_add_2)
{
    algo_lib::Integer integer0;
    algo_lib::Integer integer1;

    algo_lib::Integer result = integer0 + integer1;
    algo_lib::Integer correct_result = {{0}};

    BOOST_TEST_CHECK((result == correct_result)); 
}

BOOST_AUTO_TEST_CASE(test_minus_0)
{
    algo_lib::Integer integer0 = {{1, 0, 0, 0}};
    algo_lib::Integer integer1 = {{1}};

    algo_lib::Integer result = integer0 - integer1;
    algo_lib::Integer correct_result = {{9, 9, 9}};

    BOOST_TEST_CHECK((result == correct_result)); 
}

BOOST_AUTO_TEST_CASE(test_minus_1)
{
    algo_lib::Integer integer0 = {{1, 2, 5, 3}};
    algo_lib::Integer integer1 = {{7, 2}};

    algo_lib::Integer result = integer0 - integer1;
    algo_lib::Integer correct_result = {{1, 1, 8 ,1}};

    BOOST_TEST_CHECK((result == correct_result)); 
}

BOOST_AUTO_TEST_CASE(test_minus_2)
{
    algo_lib::Integer integer0 = {{3, 0, 0}};
    algo_lib::Integer integer1 = {{2, 9, 9}};

    algo_lib::Integer result = integer0 - integer1;
    algo_lib::Integer correct_result = {{1}};

    BOOST_TEST_CHECK((result == correct_result)); 
}

BOOST_AUTO_TEST_CASE(test_multiplication_0)
{
    algo_lib::Integer integer0 = {{1, 9, 3, 2, 6}};
    algo_lib::Integer integer1;

    algo_lib::Integer result = integer0 * integer1;
    algo_lib::Integer correct_result = {{0}};

    BOOST_TEST_CHECK((result == correct_result)); 
}

BOOST_AUTO_TEST_CASE(test_multiplication_1)
{
    algo_lib::Integer integer0 = {{8}};
    algo_lib::Integer integer1 = {{7}};

    algo_lib::Integer result = integer0 * integer1;
    algo_lib::Integer correct_result = {{5, 6}};

    BOOST_TEST_CHECK((result == correct_result)); 
}

BOOST_AUTO_TEST_CASE(test_multiplication_2)
{
    algo_lib::Integer integer0 = {{1, 2, 3, 4}};
    algo_lib::Integer integer1 = {{1, 2, 3, 4}};

    algo_lib::Integer result = integer0 * integer1;
    algo_lib::Integer correct_result = {{1, 5, 2, 2, 7, 5, 6}};

    BOOST_TEST_CHECK((result == correct_result)); 
}

BOOST_AUTO_TEST_SUITE_END()