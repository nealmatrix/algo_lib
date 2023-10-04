#define BOOST_TEST_MODULE test_vector2d
#include <boost/test/unit_test.hpp>

#include "cpp_lib/reimplement/vector2d.hpp"

BOOST_AUTO_TEST_SUITE(test_vector2d)

BOOST_AUTO_TEST_CASE(binary_minus)
{
    cpp_lib::MyVector2d v1(3, 4.5), v2(1, 2);
    cpp_lib::MyVector2d v = v1 - v2;

    std::cout << v << std::endl;
    BOOST_TEST_CHECK(v(0) == 2);
    BOOST_TEST_CHECK(v(1) == 2.5);
}

BOOST_AUTO_TEST_SUITE_END()
