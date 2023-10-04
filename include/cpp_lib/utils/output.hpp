#ifndef PRINTER_HPP_
#define PRINTER_HPP_

#include <vector>
#include <iostream>

namespace cpp_lib
{

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    for (const auto &e: v)
        os << e << " ";
    return os;
}

} // namespace cpp_lib

#endif // PRINTER_HPP_