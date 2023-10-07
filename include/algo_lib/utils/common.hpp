#ifndef ALGO_LIB_COMMON_HPP_
#define ALGO_LIB_COMMON_HPP_

#include <vector>
#include <deque>

namespace algo_lib 
{
template <typename T>
using vec_size_t = typename std::vector<T>::size_type;

template <typename T>
using deq_size_t = typename std::deque<T>::size_type;


} // namespace algo_lib

#endif // ALGO_LIB_COMMON_HPP_