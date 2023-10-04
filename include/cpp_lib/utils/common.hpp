#ifndef CPP_LIB_COMMON_HPP_
#define CPP_LIB_COMMON_HPP_

#include <vector>

namespace cpp_lib 
{
template <typename T>
using vec_size_t = typename std::vector<T>::size_type;

} // namespace cpp_lib

#endif // CPP_LIB_COMMON_HPP_