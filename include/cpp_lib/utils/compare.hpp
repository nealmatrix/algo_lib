#ifndef COMPARE_HPP_
#define COMPARE_HPP_

#include <vector>

#include <cpp_lib/utils/common.hpp>

namespace cpp_lib
{

template <typename T>
bool areVectorsSame(const std::vector<T> &v0, const std::vector<T> &v1)
{
    if (v0.size() != v1.size())
        return false;
    
    for (vec_size_t<T> i = 0; i < v0.size(); ++i)
    {
        if (v0.at(i) != v1.at(i))
            return false;
    }
    return true;
}

} // namespace cpp_lib

#endif // COMPARE_HPP_