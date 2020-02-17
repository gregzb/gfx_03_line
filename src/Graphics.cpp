#include "Graphics.hpp"
#include "Screen.hpp"
#include "Vec3.hpp"
#include "Utils.hpp"
#include "Mat4.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <limits>
#include <tuple>

Graphics::Graphics(Screen &screen) : screen(screen){};

void Graphics::drawLine(Vec3 a, Vec3 b, Color color, bool debug) const
{
    // std::cout << a.x << " " << a.y << " " << a.z << std::endl;
    // std::cout << b.x << " " << b.y << " " << b.z << std::endl;
    std::vector<Vec3> pixels = Utils::linePixels(a, b);

    for (auto pixel : pixels)
    {
        //std::cout << pixel.x << " " << pixel.y << std::endl;
        screen(pixel.y, pixel.x) = color;
        //screen.display();
    }
}

void Graphics::drawEdges(Mat4 &matrix, Color color) const
{
    for (int col = 0; col < matrix.getCols(); col += 2)
    {
        //std::cout << "before:" << std::endl;
        //screen.display();
        drawLine({matrix[0][col], matrix[1][col], matrix[2][col]}, {matrix[0][col + 1], matrix[1][col + 1], matrix[2][col + 1]}, color);
        //std::cout << "after:" << std::endl;
        //screen.toFileExtension("pls.png");
        //screen.display();
    }
}

void Graphics::clear(Color color) const
{
    for (int row = 0; row < screen.getHeight(); row++)
    {
        for (int col = 0; col < screen.getWidth(); col++)
        {
            screen(row, col) = color;
        }
    }
}
