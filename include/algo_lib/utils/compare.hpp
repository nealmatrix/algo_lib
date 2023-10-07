#ifndef ALGO_LIB_COMPARE_HPP_
#define ALGO_LIB_COMPARE_HPP_

#include <vector>

#include <algo_lib/utils/common.hpp>

namespace algo_lib
{

template <typename T>
bool same(const std::vector<T> &v0, const std::vector<T> &v1)
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

template <typename T>
bool same(const std::deque<T> &v0, const std::deque<T> &v1)
{
    if (v0.size() != v1.size())
        return false;
    
    for (deq_size_t<T> i = 0; i < v0.size(); ++i)
    {
        if (v0.at(i) != v1.at(i))
            return false;
    }
    return true;
}

} // namespace algo_lib

#endif // ALGO_LIB_COMPARE_HPP_