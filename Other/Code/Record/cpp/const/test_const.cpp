#include <iostream>

struct Point {
    int x;
    int y;
    int z;

    constexpr Point up(int d) {
        return {x, y, z + d};
    }

    constexpr Point move(int dx, int dy) const {
        return {x + dx, y + dy, z};
    }
};


constexpr Point origo {0, 0, 0};
constexpr int z = origo.x;
constexpr Point n = origo.move(1,2);

constexpr Point a[] = {origo, Point{1, 1, 1}, Point{2, 2, 2}, origo.move(3, 3)};


template<> class complex<double> {
public:
    constexpr complex(double re = 0.0, double im = 0.0);
    constexpr complex(const complex<float>&);
    explicit constexpr complex(const complex<long double>&);
    constexpr double real();
    void real(double);
    constexpr double imag();
    void imag(double);

    complex<double>& operator=(double);
    complex<double>& operator+=(double);
    // ...
};

constexpr complex<float> z1{1,2};
constexpr double re = z1.real();
constexpr double im = z1.imag();
constexpr complex<double> z2 {re, im}; // z2是z1的副本
constexpr complex<double> z3 {z1}; // z3是z1的副本

int main()
{
    return 0;
}

