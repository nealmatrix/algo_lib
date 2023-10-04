#include <iostream>

#include "cpp_lib/math/geometry/geometry.hpp"

namespace cpp_lib
{

Eigen::Vector2d calculateIntersection(const Eigen::Vector2d &a, const Eigen::Vector2d &b, const Eigen::Vector2d &c, const Eigen::Vector2d &d, Eigen::Vector2d &intersection)
{
    // OA + tAB = OC + sCD
    double r = (b(0) - a(0)) * (d(1) - c(1)) - (b(1) - a(1)) * (d(0) - c(0));

    if (r == 0)
    {
        std::cout << "ab is parrallel to cd\na:\n" << a << "b:\n" << b << "c:\n" << c << "d:\n" << d;
        intersection << 0, 0;
        return {0, 0};
    }

    double t = ((a(1) - c(1)) * (d(0) - c(0)) - (a(0) - c(0)) * (d(1) - c(1))) / r;
    double s = ((a(1) - c(1)) * (b(0) - a(0)) - (a(0) - c(0)) * (b(1) - a(1))) / r;

    Eigen::Vector2d ab = b - a;
    intersection = a + t * ab;

    return {t, s};
}

} // namespace cpp_lib