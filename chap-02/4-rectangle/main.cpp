#include "Rectangle.h"

#include <iostream>

int main()
{
    Rectangle rect(2.f, 4.f);
    std::cout << rect << std::endl;

    rect.scale(3);
    std::cout << rect << std::endl;

    Rectangle square (2.5);
    std::cout << rect << std::endl;

    Rectangle::set_default_size(3.f);

    Rectangle s1;
    Rectangle s2;
    std::cout << "{ L: " << s1.get_length() << ", W: " << s1.get_width() << " }" << std::endl;
    std::cout << "{ L: " << s2.get_length() << ", W: " << s2.get_width() << " }" << std::endl;

    Rectangle::set_default_size(5.f);

    Rectangle s3;
    Rectangle s4;
    Rectangle s5;

    std::cout << "{ L: " << s3.get_length() << ", W: " << s3.get_width() << " }" << std::endl;
    std::cout << "{ L: " << s4.get_length() << ", W: " << s4.get_width() << " }" << std::endl;
    std::cout << "{ L: " << s5.get_length() << ", W: " << s5.get_width() << " }" << std::endl;

    // At this point, size of s1 and s2 shoud be 3.f, and size fo s3, s4 and s5 should be 5.f. l

    return 0;
}
