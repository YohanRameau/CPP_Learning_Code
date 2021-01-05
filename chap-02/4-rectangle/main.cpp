#include "Rectangle.h"

#include <iostream>

int main()
{
    Rectangle rect_1(2.f, 4.f);
    std::cout << rect_1 << std::endl;

    rect_1.scale(3);
    std::cout << rect_1 << std::endl;

    Rectangle rect_2(2.5f);
    std::cout << rect_2 << std::endl;

    Rectangle rect_3;
    std::cout << rect_3 << std::endl;

    Rectangle::set_default_size(7.f);

    Rectangle rect_4;
    std::cout << rect_4 << std::endl;

    return 0;
}
