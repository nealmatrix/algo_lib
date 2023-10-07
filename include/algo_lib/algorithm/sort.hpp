#ifndef ALGO_LIB_SORT_HPP_
#define ALGO_LIB_SORT_HPP_

#include <vector>
#include <cstdint>
#include <algorithm>

#include <algo_lib/utils/common.hpp>

namespace algo_lib
{

template <typename T>
void selectionSort(std::vector<T> &v)
{
    vec_size_t<T> min_id = 0;
    T tmp;

    for(vec_size_t<T> i = 0; i < v.size(); ++i)
    {
        min_id = i;

        for(vec_size_t<T> j = i + 1; j < v.size(); ++j)
        {
            if (v.at(j) < v.at(min_id))
                min_id = j;
        }

        if (min_id != i)
            std::swap(v.at(i), v.at(min_id));
    }
}

template <typename T>
void insertionSort(std::vector<T> &v)
{
    T key;
    vec_size_t<T> j;

    for (vec_size_t<T> i = 1; i < v.size(); ++i)
    {
        key = v.at(i);

        j = 1;

        for (; j <= i; ++j)
        {
            if (v.at(i - j) > key)
                v.at(i - j + 1) = v.at(i - j);
            else
                break;
        }

        v.at(i - j + 1) = key;
    }
}

template <typename T>
void bubbleSort(std::vector<T> &v)
{
    T tmp;
    bool swap;

    for (vec_size_t<T> i = 0; i < v.size(); ++i)
    {
        swap = false;

        for (vec_size_t<T> j = 0; j < v.size() - 1 - i; ++j)
        {
            if (v.at(j) > v.at(j + 1))
            {
                std::swap(v.at(j), v.at(j + 1));
                swap = true;
            }
        }

        if (!swap)
            break;
    }
}

template <typename T>
void mergeSort(std::vector<T> &v, vec_size_t<T> begin, vec_size_t<T> end)
{
    if (end - begin == 0 || end - begin == 1)
        return;
    
    vec_size_t<T> mid = (begin + end) / 2; 
    mergeSort(v, begin, mid);
    mergeSort(v, mid, end);

    std::vector<T> left(v.begin() + begin, v.begin() + mid);
    std::vector<T> right(v.begin() + mid, v.begin() + end);

    vec_size_t<T> i = 0, j = 0;

    for (vec_size_t<T> k = 0; k < end - begin; ++k)
    {
        if (i >= mid - begin)
        {
            v.at(begin + k) = right.at(j);
            ++j;
            continue;
        }

        if (j >= end - mid)
        {
            v.at(begin + k) = left.at(i);
            ++i;
            continue;
        }

        if (left.at(i) < right.at(j))
        {
            v.at(begin + k) = left.at(i);
            ++i;
        }
        else
        {
            v.at(begin + k) = right.at(j);
            ++j;
        }
    }
}

template <typename T>
void mergeSort(std::vector<T> &v)
{
    mergeSort(v, 0, v.size());    
}

template <typename T>
std::pair<std::vector<T>, std::uint32_t> countInversions(std::vector<T> &v, vec_size_t<T> begin, vec_size_t<T> end)
{
    if (end - begin == 0)
        return {{}, 0};

    if (end - begin == 1)
        return {{v.at(begin)}, 0};

    vec_size_t<T> mid = (begin + end) / 2;    

    auto pair_left = countInversions(v, begin, mid);
    const auto &left = pair_left.first;

    auto pair_right = countInversions(v, mid, end);
    const auto &right = pair_right.first;

    vec_size_t<T> i = 0, j = 0, split_inversions_num = 0;

    std::vector<T> result;

    for (vec_size_t<T> k = 0; k < end - begin; ++k)
    {
        if (i >= mid - begin)
        {
            result.push_back(right.at(j));
            ++j;
            continue;
        }

        if (j >= end - mid)
        {
            result.push_back(left.at(i));
            ++i;
            continue;
        }

        if (left.at(i) < right.at(j))
        {
            result.push_back(left.at(i));
            ++i;
        }
        else
        {
            result.push_back(right.at(j));
            ++j;
            split_inversions_num += mid - i - begin;
        }
    }

    return {result, pair_left.second + split_inversions_num + pair_right.second};
}

template <typename T>
std::pair<std::vector<T>, uint32_t> countInversions(std::vector<T> &v)
{
    return countInversions(v, 0, v.size());
}

} // namespace algo_lib

#endif // ALGO_LIB_SORT_HPP_