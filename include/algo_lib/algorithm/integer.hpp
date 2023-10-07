#ifndef ALGO_LIB_INTEGER_HPP_
#define ALGO_LIB_INTEGER_HPP_

#include <iostream>
#include <vector>

#include "algo_lib/utils/common.hpp"

namespace algo_lib
{

class Integer
{

friend std::ostream &operator<<(std::ostream &os, const Integer&integer);

public:
    Integer() = default;
    Integer(const std::vector<int> &v);

public:
    std::string toString() const;
    vec_size_t<int> size() const {return reverse_digits_.size();}

    bool operator==(const Integer &integer);
    Integer operator+(const Integer &integer);
    Integer operator-(const Integer &integer);
    // karatsuba multiplication
    Integer operator*(const Integer &integer);

private:
    int at(vec_size_t<int> i) const {return reverse_digits_.at(i);}
    void push_back(int i) {reverse_digits_.push_back(i);}
    void pop_back() {reverse_digits_.pop_back();}

private:
    std::vector<int> reverse_digits_;

};

} // namespace algo_lib

#endif // ALGO_LIB_INTEGER_HPP_