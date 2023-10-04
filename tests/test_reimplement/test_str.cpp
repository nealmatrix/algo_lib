#define BOOST_TEST_MODULE test_str

#include <boost/test/unit_test.hpp>
#include "cpp_lib/reimplement/str.hpp"

BOOST_AUTO_TEST_SUITE(test_str)
BOOST_AUTO_TEST_CASE(my_strcmp_0)
{
    char s1[] = "abc";
    char s2[] = "bc";

    BOOST_TEST_CHECK(cpp_lib::myStrcmp(s1, s2) == -1);
}

BOOST_AUTO_TEST_CASE(my_strcmp_1)
{
    char s1[] = "abc";
    char s2[] = "abc";

    BOOST_TEST_CHECK(cpp_lib::myStrcmp(s1, s2) == 0);
}

BOOST_AUTO_TEST_CASE(my_strcmp_2)
{
    char s1[] = "xbc";
    char s2[] = "bcde";

    BOOST_TEST_CHECK(cpp_lib::myStrcmp(s1, s2) == 1);
}

BOOST_AUTO_TEST_CASE(my_strcmp_3)
{
    char s1[] = "bcd";
    char s2[] = "bcde";

    BOOST_TEST_CHECK(cpp_lib::myStrcmp(s1, s2) == -1);
}
BOOST_AUTO_TEST_SUITE_END()