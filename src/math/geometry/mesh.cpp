#include "cpp_lib/math/geometry/triangle.hpp"
#include "cpp_lib/math/geometry/mesh.hpp"

namespace cpp_lib
{

bool Mesh::isCounterClockWise(size_t id0, size_t id1, size_t id2)
{
    return Triangle(points(id0), points(id1), points(id2)).isCounterClockWise();
}

void Mesh::sort3PointsCounterClockWise(std::vector<size_t> &point_ids)
{
    if (point_ids.size() != 3)
        throw std::runtime_error("Vector size mush be 3");
    
    if (!isCounterClockWise(point_ids.at(0), point_ids.at(1), point_ids.at(2)))
        std::swap(point_ids.at(1), point_ids.at(2));
}

void Mesh::sort4PointsCounterClockWise(std::vector<size_t> &point_ids)
{
    if (point_ids.size() != 4)
        throw std::runtime_error("Vector size mush be 4");
    
    auto &p0 = point_ids.at(0);
    auto &p1 = point_ids.at(1);
    auto &p2 = point_ids.at(2);
    auto &p3 = point_ids.at(3);

    if (isCounterClockWise(p0, p1, p2))
    {
        if (isCounterClockWise(p0, p1, p3))
        {
            if (!isCounterClockWise(p0, p2, p3))
                std::swap(p2, p3);
        }
        else
            std::swap(p0, p3);
    }
    else
    {
        if (isCounterClockWise(p0, p1, p3))
            std::swap(p1, p2);
        else
        {
            if (isCounterClockWise(p0, p2, p3))
                std::swap(p0, p1);
            else
                std::swap(p0, p2);
        }
    }
}

} // namespace cpp_lib