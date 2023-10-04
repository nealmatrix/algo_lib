#include <vector>
#include <iostream>

#include "cpp_lib/vector2d.hpp"

int main()
{
    cpp_lib::Vector2d v1(3, 4.5), v2(1, 2);
    cpp_lib::Vector2d v = v1 - v2;

    std::cout << v << std::endl;
}