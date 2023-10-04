#ifndef CPP_LIB_GEOMETRY_HPP_
#define CPP_LIB_GEOMETRY_HPP_

#include <Eigen/Dense>

namespace cpp_lib
{

Eigen::Vector2d calculateIntersection(const Eigen::Vector2d &a, const Eigen::Vector2d &b, const Eigen::Vector2d &c, const Eigen::Vector2d &d, Eigen::Vector2d &intersection);
} // namespace cpp_lib

#endif // CPP_LIB_VECTOR_HPP_