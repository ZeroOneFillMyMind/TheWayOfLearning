#include <iostream>

int main()
{
    char *p = new char{'x'};
    std::cout << *p << std::endl;

    delete p;

    return 0;
}
