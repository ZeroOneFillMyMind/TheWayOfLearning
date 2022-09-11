// Chapter 7

#include <iostream>
#include <string>

using namespace std;

// 7-2
class Sales_data {
    friend istream &read(istream& is, Sales_data &item);
    friend ostream &print(ostream &os, const Sales_data &item);
private:
    string bookNo;
    unsigned units_sold{};
    double sellingprice{};
    double saleprice{};
    double discount{};
    double revenue{};

public:
    string isbn() const {return bookNo;}

    Sales_data &combine(const Sales_data &rhs)
    {
        units_sold += rhs.units_sold;
        saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);

        if (sellingprice != 0) {
            discount = saleprice / sellingprice;
        }

        return *this;
    }
};

// 7-4
class Person {
    friend istream &read(istream &is, Person &per);
    friend ostream &print(ostream &is, const Person &per);
private:
    string name;
    string address;
public:
    string GetName() const {return name;}
    string GetAddr() const {return address;}
};

istream &read(istream& is, Sales_data &item)
{
    double price{};
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold;
    return os;
}

// 7-31
class X;
class Y {
    X*  x;
};

class X {
    Y y;
};

// 7-32
class Window_mgr {
public:
    void clear();
};

class Screen {
    friend void Window_mgr::clear();
private:
    unsigned height = 0;
    unsigned width = 0;
    unsigned cursor = 0;
    string contents;
public:
    Screen() = default;
    Screen(unsigned ht, unsigned wd, char c): height(ht), width(wd), contents(ht*wd, c) {}
};

// typedef string Type;
// Type initVal();
// class Exercise {
// public:
//     typedef double Type;
//     Type setVal(Type);
//     Type initVal();
// private:
//     int val;
// };

// Type Exercise::setVal(Type param)
// {
//     val = param + initVal();
//     return val;
// }

class NoDefault {
public:
    NoDefault(int i) {
        val = i;
    }

    int val;
};

class C {
public:
    NoDefault nd;
    C(int i = 0) : nd(i) {}
};

int main()
{
    cout << "input record:" << endl;
    Sales_data total;
    if (cin >> total) {
        Sales_data trans;
        while (cin >> trans) {
            if (total.isbn() == trans.isbn) {
                total.combine(trans);
            } else {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    } else {
        cerr << "No data?" << endl;
        return -1;
    }

    return 0;
}