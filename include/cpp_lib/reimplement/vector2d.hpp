#ifndef CPP_LIB_VECTOR2D_HPP_
#define CPP_LIB_VECTOR2D_HPP_

#include <iostream>
#include <array>

#include "cpp_lib/utils/common.hpp"

namespace cpp_lib 
{

class MyVector2d;

MyVector2d operator-(const MyVector2d &, const MyVector2d &);

class MyVector2d
{
friend std::ostream &operator<<(std::ostream &os, const MyVector2d& v);
using scalar_t = double;
using size_t = unsigned;

public:
    MyVector2d() = default;
    MyVector2d(scalar_t x, scalar_t y)
    {
        array_[0] = x;
        array_[1] = y;
    }

    MyVector2d(const MyVector2d &) = delete;
    MyVector2d(MyVector2d &&) = default;

    MyVector2d &operator=(const MyVector2d &) = delete;
    MyVector2d &operator=(MyVector2d &&) = default; 

public:
    scalar_t operator()(size_t i) const {return array_[i];}
    scalar_t &operator()(size_t i) {return array_[i];}

private:
    std::array<scalar_t, 2> array_;
};

} // namspace cpp_lib

#endif // CPP_LIB_VECTOR2D_HPP_