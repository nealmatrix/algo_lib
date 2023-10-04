#ifndef CPP_LIB_TRIANGLE_HPP_
#define CPP_LIB_TRIANGLE_HPP_

#include <Eigen/Dense>

namespace cpp_lib
{

class Triangle
{
public:
    Triangle(Eigen::Vector2d p0, Eigen::Vector2d p1, Eigen::Vector2d p2): p0_(p0), p1_(p1), p2_(p2){}

    double signedArea() const {return 0.5 * ((p1_(0) - p0_(0)) * (p2_(1) - p0_(1)) - (p2_(0) - p0_(0)) * (p1_(1) - p0_(1)));}
    bool isCounterClockWise() const {return signedArea() > 0;}

private:
    Eigen::Vector2d p0_;
    Eigen::Vector2d p1_;
    Eigen::Vector2d p2_;
};

} // namespace cpp_lib

#endif // CPP_LIB_TRIANGLE_HPP_
