#define BOOST_TEST_MODULE test_math

#include <boost/test/unit_test.hpp>

#include "cpp_lib/math/geometry/mesh.hpp"
#include "cpp_lib/utils/compare.hpp"
#include "cpp_lib/utils/output.hpp"

struct MeshFixture
{
    MeshFixture()
    {
        Eigen::Vector2d a(0, 0);
        Eigen::Vector2d b(1, 0);
        Eigen::Vector2d c(1, 1);
        Eigen::Vector2d d(0, 1);

        mesh.points() = {a, b, c, d};
    }
    ~MeshFixture() {}

    cpp_lib::Mesh mesh;
};

BOOST_FIXTURE_TEST_SUITE(test_mesh, MeshFixture)

BOOST_AUTO_TEST_CASE(test_sort_3_points_counterclockwise_0)
{
    std::vector<cpp_lib::Mesh::size_t> point_ids = {0, 3, 1};
    mesh.sort3PointsCounterClockWise(point_ids);

    using cpp_lib::operator<<;
    std::cout << point_ids << std::endl;
    BOOST_TEST_CHECK(cpp_lib::areVectorsSame(point_ids, {0, 1, 3}));
}

BOOST_AUTO_TEST_CASE(test_sort_4_points_counterclockwise_0)
{
    std::vector<cpp_lib::Mesh::size_t> point_ids = {0, 1, 2, 3};
    mesh.sort4PointsCounterClockWise(point_ids);

    using cpp_lib::operator<<;
    std::cout << point_ids << std::endl;

    bool correct = 
        cpp_lib::areVectorsSame(point_ids, {0, 1, 2, 3}) ||
        cpp_lib::areVectorsSame(point_ids, {1, 2, 3, 0}) ||
        cpp_lib::areVectorsSame(point_ids, {2, 3, 0, 1}) ||
        cpp_lib::areVectorsSame(point_ids, {3, 0, 1, 2});

    BOOST_TEST_CHECK(correct);
}

BOOST_AUTO_TEST_CASE(test_sort_4_points_counterclockwise_1)
{
    std::vector<cpp_lib::Mesh::size_t> point_ids = {0, 1, 3, 2};
    mesh.sort4PointsCounterClockWise(point_ids);

    using cpp_lib::operator<<;
    std::cout << point_ids << std::endl;

    bool correct = 
        cpp_lib::areVectorsSame(point_ids, {0, 1, 2, 3}) ||
        cpp_lib::areVectorsSame(point_ids, {1, 2, 3, 0}) ||
        cpp_lib::areVectorsSame(point_ids, {2, 3, 0, 1}) ||
        cpp_lib::areVectorsSame(point_ids, {3, 0, 1, 2});

    BOOST_TEST_CHECK(correct);
}

BOOST_AUTO_TEST_CASE(test_sort_4_points_counterclockwise_2)
{
    std::vector<cpp_lib::Mesh::size_t> point_ids = {0, 2, 1, 3};
    mesh.sort4PointsCounterClockWise(point_ids);

    using cpp_lib::operator<<;
    std::cout << point_ids << std::endl;

    bool correct = 
        cpp_lib::areVectorsSame(point_ids, {0, 1, 2, 3}) ||
        cpp_lib::areVectorsSame(point_ids, {1, 2, 3, 0}) ||
        cpp_lib::areVectorsSame(point_ids, {2, 3, 0, 1}) ||
        cpp_lib::areVectorsSame(point_ids, {3, 0, 1, 2});

    BOOST_TEST_CHECK(correct);
}
BOOST_AUTO_TEST_CASE(test_sort_4_points_counterclockwise_3)
{
    std::vector<cpp_lib::Mesh::size_t> point_ids = {0, 2, 3, 1};
    mesh.sort4PointsCounterClockWise(point_ids);

    using cpp_lib::operator<<;
    std::cout << point_ids << std::endl;

    bool correct = 
        cpp_lib::areVectorsSame(point_ids, {0, 1, 2, 3}) ||
        cpp_lib::areVectorsSame(point_ids, {1, 2, 3, 0}) ||
        cpp_lib::areVectorsSame(point_ids, {2, 3, 0, 1}) ||
        cpp_lib::areVectorsSame(point_ids, {3, 0, 1, 2});

    BOOST_TEST_CHECK(correct);
}
BOOST_AUTO_TEST_CASE(test_sort_4_points_counterclockwise_4)
{
    std::vector<cpp_lib::Mesh::size_t> point_ids = {0, 3, 1, 2};
    mesh.sort4PointsCounterClockWise(point_ids);

    using cpp_lib::operator<<;
    std::cout << point_ids << std::endl;

    bool correct = 
        cpp_lib::areVectorsSame(point_ids, {0, 1, 2, 3}) ||
        cpp_lib::areVectorsSame(point_ids, {1, 2, 3, 0}) ||
        cpp_lib::areVectorsSame(point_ids, {2, 3, 0, 1}) ||
        cpp_lib::areVectorsSame(point_ids, {3, 0, 1, 2});

    BOOST_TEST_CHECK(correct);
}
BOOST_AUTO_TEST_CASE(test_sort_4_points_counterclockwise_5)
{
    std::vector<cpp_lib::Mesh::size_t> point_ids = {0, 3, 2, 1};
    mesh.sort4PointsCounterClockWise(point_ids);

    using cpp_lib::operator<<;
    std::cout << point_ids << std::endl;

    bool correct = 
        cpp_lib::areVectorsSame(point_ids, {0, 1, 2, 3}) ||
        cpp_lib::areVectorsSame(point_ids, {1, 2, 3, 0}) ||
        cpp_lib::areVectorsSame(point_ids, {2, 3, 0, 1}) ||
        cpp_lib::areVectorsSame(point_ids, {3, 0, 1, 2});

    BOOST_TEST_CHECK(correct);
}

BOOST_AUTO_TEST_SUITE_END()