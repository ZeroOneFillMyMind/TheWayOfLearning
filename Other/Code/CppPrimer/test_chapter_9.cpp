#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <forward_list>

using namespace std;

void test_9_11()
{
    vector<int> ilist1;            // default initialization, size = 0, capacity = 0
    vector<int> ilist2(ilist1);    // copy, same capacity and elements
    vector<int> ilist2_2 = ilist1; // equal to approach 2
    vector<int> ilist3 = {1, 2, 3, 4, 5};
    vector<int> ilist3_2{1, 2, 3, 4, 5};
    vector<int> ilist4(ilist1.begin() + 2, ilist1.end() - 1);
    vector<int> ilist5(7);
    vector<int> ilist6(7, 3);
}

void test_9_13()
{
    list<int> ilist{1, 2, 3, 4, 5, 6, 7};
    vector<int> ivec{7, 6, 5, 4, 3, 2, 1};
    // vector<double> ivec(ilist); // error, different container
    vector<double> dvec(ilist.begin(), ilist.end());
    vector<double> dvec2(ivec.begin(), ivec.end());
    // vector<double> dvec3(ivec); // error, different element type

    list<string> names;
    vector<const char *> oldStyle;
    // names = oldStyle; // error, container is not matched
    names.assign(oldStyle.cbegin(), oldStyle.cend());

    list<string> slist1(1);
    slist1.assign(10, "Hiya!");
}

void test()
{
    vector<int> c;
    if (!c.empty())
    {
        auto val = *c.begin(), val2 = c.front();
        auto last = c.end();
        auto val3 = *(--last);
        auto val4 = c.back();
    }

    if (!c.empty())
    {
        c.front() = 42;
        auto &v = c.back();
        v = 2;
        auto v2 = c.back();
        v2 = 45; // cant change the val in c
    }
}

void test2()
{
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2)
        {
            curr = flst.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }
}

void test3()
{
    vector<int> vi = {0, 1, 2, 3, 4, 5};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            iter += 2;
        }
        else
        {
            iter = vi.erase(iter);
        }
    }

    for (auto elem : vi)
    {
        cout << elem << endl;
    }
}

void test4()
{
    vector<int> vec{1, 2, 3, 4};
    vec.reserve(10);
    cout << "size():" << vec.size() << " cap():" << vec.capacity() << endl;
    vec.shrink_to_fit();
    cout << "after shrink size():" << vec.size() << " cap():" << vec.capacity() << endl;
}

void test5()
{
    string s{};
    s.insert(s.size(), 5, '!');
    cout << s << endl;
    s.erase(s.size() - 2, 2);
    cout << s << endl;

    const char *cp = "stately, plump buck";
    s.assign(cp, 7);
    cout << s << endl;
    s.insert(s.size(), cp + 7);
    cout << s << endl;
}

void test6()
{
    string s("C++ Primer");
    string s2 = s;
    s.insert(s.size(), " 4th Ed.");
    s2.append(" 4th Ed.");
    cout << "s:" << s << endl;
    cout << "s2:" << s2 << endl;

    string s3(s);
    s.erase(11, 3);
    s.insert(11, "5th");
    s2.replace(11, 3, "5th");
    cout << "s:" << s << endl;
    cout << "s2:" << s2 << endl;

    s3.replace(11, 3, "Fifth");
    cout << "s3:" << s3 << endl;
}

void test7()
{
    string s{"03174p3"};
    string number{"0123456789"};
    auto pos = s.find_first_not_of(number);
    cout << "first not: " << pos << endl;
}

int main()
{
    // vector<int> vec{};
    // std::cout << vec.at(1) << std::endl;

    test3();
    test4();
    test5();

    test6();
    test7();
    return 0;
}