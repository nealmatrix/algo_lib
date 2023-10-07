#define BOOST_TEST_MODULE test_sort

#include <boost/test/unit_test.hpp>

#include "algo_lib/algorithm/sort.hpp"
#include "algo_lib/utils/compare.hpp"

BOOST_AUTO_TEST_SUITE(test_sort)

BOOST_AUTO_TEST_CASE(test_sort_0)
{
    std::vector<double> v = {2.2, 0.9, 1, 5.1, 3.4};
    std::vector<double> v_sort = {0.9, 1, 2.2, 3.4, 5.1};

    auto v0 = v;
    algo_lib::selectionSort(v0);
    BOOST_TEST_CHECK(algo_lib::same(v0, v_sort));

    auto v1 = v;
    algo_lib::insertionSort(v1);
    BOOST_TEST_CHECK(algo_lib::same(v1, v_sort));

    auto v2 = v;
    algo_lib::bubbleSort(v2);
    BOOST_TEST_CHECK(algo_lib::same(v2, v_sort));

    auto v3 = v;
    algo_lib::mergeSort(v3);
    BOOST_TEST_CHECK(algo_lib::same(v3, v_sort));

    auto v4 = v;
    auto inversions_num = algo_lib::countInversions(v4);
    BOOST_TEST_CHECK(algo_lib::same(v4, v_sort));
    BOOST_TEST_CHECK(inversions_num == 3);
}

BOOST_AUTO_TEST_CASE(test_sort_1)
{
    std::vector<int> v = {5, 4, 3, 2, 1};
    std::vector<int> v_sort = {1, 2, 3, 4, 5};

    auto v0 = v;
    algo_lib::selectionSort(v0);
    BOOST_TEST_CHECK(algo_lib::same(v0, v_sort));

    auto v1 = v;
    algo_lib::insertionSort(v1);
    BOOST_TEST_CHECK(algo_lib::same(v1, v_sort));

    auto v2 = v;
    algo_lib::bubbleSort(v2);
    BOOST_TEST_CHECK(algo_lib::same(v2, v_sort));

    auto v3 = v;
    algo_lib::mergeSort(v3);
    BOOST_TEST_CHECK(algo_lib::same(v3, v_sort));

    auto v4 = v;
    auto inversions_num = algo_lib::countInversions(v4);
    BOOST_TEST_CHECK(algo_lib::same(v4, v_sort));
    BOOST_TEST_CHECK(inversions_num == 10);
}

BOOST_AUTO_TEST_CASE(test_sort_2)
{
    std::vector<int> v = {1};
    std::vector<int> v_sort = {1};

    auto v0 = v;
    algo_lib::selectionSort(v0);
    BOOST_TEST_CHECK(algo_lib::same(v0, v_sort));

    auto v1 = v;
    algo_lib::insertionSort(v1);
    BOOST_TEST_CHECK(algo_lib::same(v1, v_sort));

    auto v2 = v;
    algo_lib::bubbleSort(v2);
    BOOST_TEST_CHECK(algo_lib::same(v2, v_sort));

    auto v3 = v;
    algo_lib::mergeSort(v3);
    BOOST_TEST_CHECK(algo_lib::same(v3, v_sort));

    auto v4 = v;
    auto inversions_num = algo_lib::countInversions(v4);
    BOOST_TEST_CHECK(algo_lib::same(v4, v_sort));
    BOOST_TEST_CHECK(inversions_num == 0);
}

BOOST_AUTO_TEST_CASE(test_sort_3)
{
    std::vector<int> v = {1, 2, 3};
    std::vector<int> v_sort = {1, 2, 3};

    auto v0 = v;
    algo_lib::selectionSort(v0);
    BOOST_TEST_CHECK(algo_lib::same(v0, v_sort));

    auto v1 = v;
    algo_lib::insertionSort(v1);
    BOOST_TEST_CHECK(algo_lib::same(v1, v_sort));

    auto v2 = v;
    algo_lib::bubbleSort(v2);
    BOOST_TEST_CHECK(algo_lib::same(v2, v_sort));

    auto v3 = v;
    algo_lib::mergeSort(v3);
    BOOST_TEST_CHECK(algo_lib::same(v3, v_sort));

    auto v4 = v;
    auto inversions_num = algo_lib::countInversions(v4);
    BOOST_TEST_CHECK(algo_lib::same(v4, v_sort));
    BOOST_TEST_CHECK(inversions_num == 0);
}

BOOST_AUTO_TEST_SUITE_END()