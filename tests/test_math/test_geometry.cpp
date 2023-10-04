#define BOOST_TEST_MODULE test_math

#include <boost/test/unit_test.hpp>

#include "cpp_lib/math/geometry/geometry.hpp"

BOOST_AUTO_TEST_SUITE(test_geometry)

BOOST_AUTO_TEST_CASE(test_intersection_0)
{
    Eigen::Vector2d a = {0, 1};
    Eigen::Vector2d b = {1, 1};
    Eigen::Vector2d c = {1, 0};
    Eigen::Vector2d d = {0, 3};
    Eigen::Vector2d intersection;

    Eigen::Vector2d t_s = cpp_lib::calculateIntersection(a, b, c, d, intersection);

    BOOST_CHECK_SMALL(t_s(0) - 2.0 / 3, 1e-8);
    BOOST_CHECK_SMALL(t_s(1) - 1.0 / 3, 1e-8);

    BOOST_CHECK_SMALL(intersection(0) - 2.0 / 3, 1e-8);
    BOOST_CHECK_SMALL(intersection(1) - 1.0, 1e-8);
}
BOOST_AUTO_TEST_SUITE_END()