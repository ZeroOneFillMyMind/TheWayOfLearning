#include <iostream>
#include <string>
#include <vector>
#include <limits>

using std::string;
using std::vector;
using std::numeric_limits;

#if 0
void print_modulo(const vector<int>& v, ostream& os, int m)
{
    for_each(begin(v), end(v)),
        [&os, m](int x){ if(x%m == 0) os << x << '\n';}
    );
}
#endif

#if 0
// 错误表达
auto rev = [&rev](char* b, char* e)
    {if (1 < e-b) {swap(*b, *--e); rev(++b, e);}};

#endif

#if 0
void f(string& s1, string& s2)
{
    function<void(char* b, char* e)> rev = [&](char* b, char* e){if (1 < e - b) {swap(*b, *--e); rev(++b, e);}}
    rev(&s1[0], &s1[0] + s1.size());
    rev(&s2[0], &s2[0] + s2.size());
}

#endif

int main()
{
    static_assert(sizeof(int) == sizeof(float), "unexpected sizes");
    std::cout << sizeof(int) << " vs " << sizeof(double) << std::endl;
    std::cout << sizeof(int) << " vs " << sizeof(float) << std::endl;

    int x = numeric_limits<int>::max();
    // double d = x;
    float d = x;
    int y = x;

    std::cout << d << std::endl;
    std::cout << y << std::endl;

    return 0;
}