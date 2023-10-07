#ifndef ALGO_LIB_COMPARE_HPP_
#define ALGO_LIB_COMPARE_HPP_

#include <vector>

#include <algo_lib/utils/common.hpp>

namespace algo_lib
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

} // namespace algo_lib

#endif // COMPARE_HPP_