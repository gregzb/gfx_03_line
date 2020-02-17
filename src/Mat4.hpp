#pragma once

#include <vector>
#include <string>

#include "Vec3.hpp"

class Mat4
{
private:
    std::vector<std::vector<double>> m;
    int cols;

public:
    Mat4(int cols);
    Mat4(std::vector<std::vector<double>> m);
    std::vector<double> &operator[](int idx);
    int getRows() const;
    int getCols() const;
    std::string toString() const;

    void clear();
    Mat4 multiply(const Mat4 &matrix);
    void multiplyMutate(const Mat4 &matrix);
    void addPoint(Vec3 v);
    void addEdge(Vec3 v0, Vec3 v1);

    static Mat4 identity();
};