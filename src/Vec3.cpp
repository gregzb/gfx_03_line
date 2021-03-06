#include "Vec3.hpp"
#include <cmath>

Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z)
{
}

Vec3::Vec3(double x, double y) : x(x), y(y), z(0)
{
}

double Vec3::magnitude()
{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
}

double Vec3::dot(Vec3 other)
{
    return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::normalize()
{
    double mag = magnitude();
    return {x / mag, y / mag, z / mag};
}

Vec3 Vec3::negate()
{
    return {-x, -y, -z};
}

Vec3 Vec3::cross(Vec3 other)
{
    return {y * other.z - z * y, z * other.x - x * other.z, x * other.y - y * other.x};
}

Vec3 Vec3::scale(Vec3 other)
{
    return {x * other.x, y * other.y, z * other.z};
}

Vec3 Vec3::scale(double other)
{
    return {x * other, y * other, z * other};
}

Vec3 Vec3::add(Vec3 other)
{
    return {x + other.x, y + other.y, z + other.z};
}

Vec3 Vec3::add(double other)
{
    return {x + other, y + other, z + other};
}

Vec3 Vec3::sub(Vec3 other)
{
    return {x - other.x, y - other.y, z - other.z};
}

Vec3 Vec3::sub(double other)
{
    return {x - other, y - other, z - other};
}