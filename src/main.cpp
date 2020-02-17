#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
#include <limits>

#include <chrono>

#include "Utils.hpp"
#include "PixelGrid.hpp"
#include "Screen.hpp"
#include "Mat4.hpp"

int main()
{

    using namespace std::chrono;
    std::cout << "\nTest add edge. Adding (1, 2, 3), (4, 5, 6) m2 =" << std::endl;
    Mat4 m2(0);
    m2.addEdge({1, 2, 3}, {4, 5, 6});
    std::cout << m2.toString() << std::endl;

    std::cout << "\nTesting ident. m1 =" << std::endl;
    Mat4 m1 = Mat4::identity();
    std::cout << m1.toString() << std::endl;

    std::cout << "\nTesting Matrix mult. m1 * m2 =" << std::endl;
    //m2 = m1.multiply(m2);
    m2.multiplyMutate(m1);
    std::cout << m2.toString() << std::endl;

    std::cout << "\nTesting Matrix mult. m1 =" << std::endl;
    //m2 = m1.multiply(m2);
    m1.clear();
    m1.addEdge({1, 2, 3}, {4, 5, 6});
    m1.addEdge({7, 8, 9}, {10, 11, 12});
    std::cout << m1.toString() << std::endl;

    std::cout << "\nTesting Matrix mult. m1 * m2 =" << std::endl;
    //m2 = m1.multiply(m2);
    m2.multiplyMutate(m1);
    std::cout << m2.toString() << std::endl;

    Mat4 edges(0);
    edges.addEdge({50, 450}, {100, 450});
    edges.addEdge({50, 450}, {50, 400});
    edges.addEdge({100, 450}, {100, 400});
    edges.addEdge({100, 400}, {50, 400});

    edges.addEdge({200, 450}, {250, 450});
    edges.addEdge({200, 450}, {200, 400});
    edges.addEdge({250, 450}, {250, 400});
    edges.addEdge({250, 400}, {200, 400});

    edges.addEdge({150, 400}, {130, 360});
    edges.addEdge({150, 400}, {170, 360});
    edges.addEdge({130, 360}, {170, 360});

    edges.addEdge({100, 340}, {200, 340});
    edges.addEdge({100, 320}, {200, 320});
    edges.addEdge({100, 340}, {100, 320});
    edges.addEdge({200, 340}, {200, 320});

    Screen screen(500, 500);
    screen.graphics.drawEdges(edges, {255, 255, 0, 255});
    screen.display();

    
    //It's a parrot :)

    // Screen screen(500, 500);
    // screen.graphics.clear({255, 255, 255, 255});

    // Mat4 edges(0);
    // std::stringstream drawing;
    // drawing.str("240 81 299 124 299 124 344 137 344 137 371 139 371 139 410 144 410 144 451 148 451 148 468 151 468 151 490 158 490 158 507 173 507 173 525 178 525 178 539 192 539 192 551 189 551 189 567 188 567 188 584 188 584 188 594 182 594 182 618 174 618 174 638 168 638 168 687 155 687 155 708 150 708 150 728 148 728 148 766 147 766 147 788 150 788 150 812 142 812 142 819 137 819 137 846 117 846 117 858 109 858 109 862 115 862 115 879 96 879 96 888 94 888 94 894 100 894 100 892 102 892 102 901 102 901 102 901 113 901 113 894 130 894 130 877 140 877 140 865 150 865 150 850 153 850 153 835 161 835 161 851 167 851 167 832 170 832 170 801 167 801 167 769 163 769 163 740 164 740 164 715 173 715 173 684 181 684 181 660 195 660 195 689 203 689 203 694 207 694 207 692 218 692 218 687 220 687 220 690 245 690 245 686 257 686 257 674 265 674 265 666 271 666 271 669 264 669 264 668 256 668 256 660 258 660 258 650 260 650 260 640 259 640 259 624 261 624 261 587 261 587 261 577 275 577 275 564 278 564 278 537 283 537 283 515 284 515 284 504 280 504 280 487 278 487 278 478 284 478 284 462 282 462 282 450 282 450 282 439 287 439 287 427 287 427 287 428 284 428 284 434 286 434 286 443 281 443 281 442 278 442 278 448 275 448 275 431 280 431 280 417 284 417 284 398 287 398 287 376 295 376 295 350 301 350 301 317 310 317 310 291 314 291 314 275 317 275 317 272 312 272 312 228 320 228 320 211 317 211 317 222 310 222 310 256 303 256 303 281 298 281 298 320 285 320 285 346 277 346 277 374 265 374 265 415 248 415 248 421 241 421 241 417 240 417 240 403 239 403 239 390 236 390 236 385 239 385 239 376 230 376 230 369 231 369 231 351 213 351 213 343 213 343 213 333 205 333 205 327 206 327 206 314 198 314 198 311 201 311 201 306 193 306 193 308 189 308 189 304 186 304 186 294 183 294 183 281 186 281 186 269 184 269 184 268 177 268 177 244 172 244 172 253 166 253 166 223 161 223 161 229 155 229 155 206 150 206 150 244 147 244 147 234 137 234 137 185 122 185 122 165 105 165 105 204 116 204 116 155 94 155 94 224 113 224 113 169 78 169 78 265 119 265 119 241 81 654 232 668 255 643 209 637 216 637 216 641 219 641 219 648 215 648 215 644 208 630 211 623 232 623 232 621 258 621 258 643 259 643 259 642 248 642 248 656 233 656 233 659 214 659 214 657 206 657 206 640 205 640 205 631 208 685 218 669 222 669 222 668 260 659 195 584 188");

    // while (drawing.rdbuf()->in_avail() != 0)
    // {
    //     double x0, y0, x1, y1;
    //     drawing >> x0 >> y0 >> x1 >> y1;

    //     edges.addEdge({x0 / 1.6 - 80, (screen.getHeight() - y0) / 1.6 + 80}, {x1 / 1.6 - 80, (screen.getHeight() - y1) / 1.6 + 80});
    //     //break;
    // }

    // screen.graphics.drawEdges(edges, {0, 0, 0, 255});
    // screen.toFileExtension("birb.png");
    // screen.display();


    // Performance testing -> mutating is 3x ish faster

    // Mat4 thing1 = {{{1, 0, 7.2, 0},
    //                 {2.2, 1, 0, 0},
    //                 {0, 0, 3.14, 98.1},
    //                 {0, 0, 16, 1}}};
    // Mat4 points(10000000);

    // for (int i = 0; i < points.getCols(); i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         points[j][i] = i * 4 + j;
    //     }
    // }

    // Mat4 copy = points;

    // high_resolution_clock::time_point t1 = high_resolution_clock::now();
    // Mat4 result = thing1.multiply(points);
    // high_resolution_clock::time_point t2 = high_resolution_clock::now();

    // duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    // std::cout << "1: " << time_span.count() << std::endl;

    // t1 = high_resolution_clock::now();
    // copy.multiplyMutate(thing1);
    // t2 = high_resolution_clock::now();

    // time_span = duration_cast<duration<double>>(t2 - t1);

    // std::cout << "2: " << time_span.count() << std::endl;

    return 0;
}