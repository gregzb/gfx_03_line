#pragma once

class Vec3
{
public:
    const double x;
    const double y;
    const double z;

    Vec3(double x, double y, double z);
    Vec3(double x, double y);
    double magnitude();
    double dot(Vec3 other);
    Vec3 normalize();
    Vec3 negate();
    Vec3 cross(Vec3 other);
    Vec3 scale(Vec3 other);
    Vec3 scale(double other);
    Vec3 add(Vec3 other);
    Vec3 add(double other);
    Vec3 sub(Vec3 other);
    Vec3 sub(double other);
};