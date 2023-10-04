#include <sstream>
#include <cmath>

#include "cpp_lib/utils/common.hpp"
#include "cpp_lib/algorithm/integer.hpp"
#include "cpp_lib/utils/compare.hpp"

namespace cpp_lib
{
std::ostream &operator<<(std::ostream &os, const Integer &integer)
{
    os << integer.toString();
    return os;
}

Integer::Integer(const std::vector<int> &v)
{
    for (vec_size_t<int> i = 0; i < v.size(); ++i)
    {
        reverse_digits_.push_back(v.at(v.size() - 1 - i));
    }
}

std::string Integer::toString() const
{
    std::ostringstream oss;
    vec_size_t<int> size = reverse_digits_.size();

    if (size == 0)
        return "0";

    for (vec_size_t<int> i = 0; i < size; ++i)
        oss << reverse_digits_.at(size - 1 - i);
    
    return oss.str();
}

bool Integer::operator==(const Integer &integer)
{
    return areVectorsSame(reverse_digits_, integer.reverse_digits_);
}

Integer Integer::operator+(const Integer &integer)
{
    Integer result;

    bool shift = false;
    int single_add_result = 0;

    const Integer *ptr = nullptr, *integer_ptr = nullptr;

    if (size() >= integer.size())
    {
        ptr = this;
        integer_ptr = &integer;
    }
    else
    {
        ptr = &integer;
        integer_ptr = this;
    }

    for (vec_size_t<int> i = 0; i < ptr->size(); ++i)
    {
        if (i < integer_ptr->size())
            single_add_result = ptr->at(i) + integer_ptr->at(i) + shift;
        else
            single_add_result = ptr->at(i) + shift;

        if (single_add_result < 10)
        {
            shift = false;
            result.push_back(single_add_result);
        }
        else
        {
            shift = true;
            result.push_back(single_add_result % 10);
        }
    }

    if(shift)
        result.push_back(1);
    
    if (result.size() == 0)
        result.push_back(0);

    return result;
}

Integer Integer::operator-(const Integer &integer)
{
    Integer result;
    bool shift = false;
    int single_minus_result = 0;

    for (vec_size_t<int> i = 0; i < size(); ++i)
    {
        if (i < integer.size())
            single_minus_result = at(i) - integer.at(i) - shift;
        else
            single_minus_result = at(i) - shift;

        if (single_minus_result >= 0)
        {
            shift = false;
            result.push_back(single_minus_result);
        }
        else if (single_minus_result < 0)
        {
            shift = true;
            result.push_back(single_minus_result + 10);
        }
    }

    while(result.at(result.size() - 1) == 0 && result.size() >= 2)
    {
        result.pop_back();
    }

    return result;
}

Integer Integer::operator*(const Integer &integer)
{
    vec_size_t<int> size0 = size();
    vec_size_t<int> size1 = integer.size();

    if (size0 == 0 || size1 == 0)
        return {{0}};

    Integer result;
    int single_multiplication_result = 0;

    if (size0 == 1 && size1 == 1)
    {
        single_multiplication_result = at(0) * integer.at(0);

        if (single_multiplication_result < 10)
            result.push_back(single_multiplication_result);
        else
        {
            result.push_back(single_multiplication_result % 10);
            result.push_back(single_multiplication_result / 10);
        }

        return result;
    }

    if (size0 != size1)
        throw std::runtime_error("two sizes mush be same");

    vec_size_t<int> n = std::floor(size0 / 2.0);
    Integer a, b, c, d;

    for (vec_size_t<int> i = 0; i < n; ++i)
        b.push_back(at(i));
    
    for (vec_size_t<int> i = n; i < size0; ++i)
        a.push_back(at(i));

    for (vec_size_t<int> i = 0; i < n; ++i)
        d.push_back(integer.at(i));
    
    for (vec_size_t<int> i = n; i < size1; ++i)
        c.push_back(integer.at(i));

    Integer ac = a * c;
    Integer bd = b * d;
    Integer tmp = (a + b) * (c + d);
    Integer bc_ad = tmp - bd - ac;

    Integer ac_with_zero, bc_ad_with_zero;

    for (vec_size_t<int> i = 0; i < 2 * n; ++i)
        ac_with_zero.push_back(0);
    
    for (const auto &digit: ac.reverse_digits_)
        ac_with_zero.push_back(digit);

    for (vec_size_t<int> i = 0; i < n; ++i)
        bc_ad_with_zero.push_back(0);
    
    for (const auto &digit: bc_ad.reverse_digits_)
        bc_ad_with_zero.push_back(digit);

    result = ac_with_zero + bc_ad_with_zero + bd;
    
    return result;
}

} // namespace cpp_lib