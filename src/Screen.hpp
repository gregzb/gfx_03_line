#pragma once

#include <string>
#include <limits>
#include "Graphics.hpp"
#include "Utils.hpp"
#include "PixelGrid.hpp"

class Screen : public PixelGrid<Color>
{
public:
    const Graphics graphics;

    Screen(int width, int height);

    void toFileAscii(std::string fileName);
    void toFile(std::string fileName);
    void toFileExtension(std::string fileName);
    void display();
};