#define BOOST_TEST_MODULE test_utils

#include <boost/test/unit_test.hpp>

#include "cpp_lib/utils/output.hpp"

BOOST_AUTO_TEST_SUITE(test_output)

BOOST_AUTO_TEST_CASE(test_vector)
{
    using cpp_lib::operator<<;
    std::vector<double> v = {1.1, 2.0, 3, 0.9};
    std::cout << v << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()