#define BOOST_TEST_MODULE test_math

#include <boost/test/unit_test.hpp>
#include "cpp_lib/math/geometry/triangle.hpp"

BOOST_AUTO_TEST_SUITE(test_triangle)

BOOST_AUTO_TEST_CASE(test_triangle_counterclosewise)
{
    Eigen::Vector2d p0(0, 0);
    Eigen::Vector2d p1(1, 2.0 / 3);
    Eigen::Vector2d p2(1.0 / 3, 1);

    BOOST_TEST_CHECK(cpp_lib::Triangle(p0, p1, p2).isCounterClockWise());
    BOOST_TEST_CHECK(!cpp_lib::Triangle(p0, p2, p1).isCounterClockWise());
}

BOOST_AUTO_TEST_SUITE_END()