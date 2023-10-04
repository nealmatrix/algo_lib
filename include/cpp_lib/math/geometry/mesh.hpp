#ifndef CPP_LIB_MESH_HPP_
#define CPP_LIB_MESH_HPP_

#include <vector>
#include <Eigen/Dense>

namespace cpp_lib
{
class Mesh
{

public:
    using size_t = unsigned;

    Mesh() = default;

    const std::vector<Eigen::Vector2d> &points() const {return points_;}
    std::vector<Eigen::Vector2d> &points() {return points_;}

    const Eigen::Vector2d &points(size_t i) const {return points_.at(i);}
    Eigen::Vector2d &points(size_t i) {return points_.at(i);}

    bool isCounterClockWise(size_t id0, size_t id1, size_t id2);
    void sort3PointsCounterClockWise(std::vector<size_t> &point_ids);
    void sort4PointsCounterClockWise(std::vector<size_t> &point_ids);

private:
    std::vector<Eigen::Vector2d> points_;
};

} // namespace cpp_lib

#endif