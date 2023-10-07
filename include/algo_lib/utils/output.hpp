#ifndef ALGO_LIB_OUTPUT_HPP_
#define ALGO_LIB_OUTPUT_HPP_

#include <vector>
#include <iostream>

namespace algo_lib
{

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    for (const auto &e: v)
        os << e << " ";
    return os;
}

} // namespace algo_lib

#endif // ALGO_LIB_OUTPUT_HPP_