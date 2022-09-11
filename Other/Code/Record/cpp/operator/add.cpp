#include <iostream>

int main()
{
    int a = -30;
    unsigned int b = 15;
    auto c = a + b;

    if (a + b > 0) {
        std::cout << "a + b > 0  -> " << std::hex << a + b << std::endl;
    } else {
        std::cout << "a + b < 0  -> " << std::hex << a + b << std::endl;
    }

    if (c > 0) {
        std::cout << "c > 0" << std::hex << c << std::endl;
    } else {
        std::cout << "c < 0" << std::hex << c << std::endl;
    }

    std::cout << "(unsigned int)a --> " << (unsigned int)a << std::endl;
    return 0;
}
