#include <iostream>
#include <limits>

int high_value(std::initializer_list<int> val)
{
    int high = std::numeric_limits<int>::min();
    if (val.size() == 0) {
        return high;
    }

    for (auto x : val) {
        if (x > high) {
            high = x;
        }
    }

    return high;
}

int main()
{
    int v1 = high_value({1,2,3,4,5,6});
    int v2 = high_value({-1, 2, v1, 4, -9, 20, v1});

    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;

    return 0;
}