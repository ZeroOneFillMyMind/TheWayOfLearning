#include <iostream>

constexpr unsigned short middle(int a)
{
    static_assert(sizeof(int) == 4, "unexpected int size");
    static_assert(sizeof(short) == 2, "unexpected short size");

    return (a >> 8) & 0xFFFF;
}

int main()
{
    int x = 0xFF00FF00;
    auto y = middle(x);

    std::cout << "y: " << std::hex << y << std::endl;

    return 0;
}
