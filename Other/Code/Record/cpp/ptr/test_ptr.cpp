#include <iostream>

void f(int n)
{
    int *p1 = new int[n];
    unique_ptr<int[]> p2{new int[n]};
    // ...
    if (n % 2) throw runtime_error("odd");
    delete[] p1;
}
