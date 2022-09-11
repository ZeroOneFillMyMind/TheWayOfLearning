#include <string>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>
#include <fstream>
#include <iterator>

using namespace std;

void test1()
{
    vector<string> svec{"i", "hate", "you"};
    auto sum = accumulate(svec.cbegin(), svec.cend(), string{""}); // 必须转换为string类型
    cout << sum << endl;
}

void test2()
{
    vector<int> ivec{1, 2, 3, 4, 5};
    vector<int> ivec2{1, 2, 3, 4, 5, 6};

    if (equal(ivec.cbegin(), ivec.cend(), ivec2.begin()))
    {
        cout << "ivec equal ivec2" << endl;
    }
}

void test3()
{
    vector<int> ivec;
    // std::fill_n(ivec.begin(), 10, 0); // Segmentation Fault

    std::fill_n(back_inserter(ivec), 10, 0);
    cout << ivec.size() << endl;

    replace(ivec.begin(), ivec.end(), 0, 1);
    for_each(ivec.begin(), ivec.end(), [](int i)
             { cout << i << endl; });
    cout << "----\n";

    vector<int> ivec2;
    replace_copy(ivec.begin(), ivec.end(), back_inserter(ivec2), 1, 2);
    cout << "ivec:\n";
    for_each(ivec.begin(), ivec.end(), [](int i)
             { cout << i << endl; });
    cout << "----\n";
    cout << "ivec2:\n";
    for_each(ivec2.begin(), ivec2.end(), [](int i)
             { cout << i << endl; });
    cout << "----\n";
}

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void test4()
{
    vector<string> sVec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(sVec);
    for_each(sVec.begin(), sVec.end(), [](const string &word)
             { cout << word << ' '; });
    cout << endl;

    // by len
    stable_sort(sVec.begin(), sVec.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    for_each(sVec.begin(), sVec.end(), [](const string &word)
             { cout << word << ' '; });
    cout << endl;
}

void test5()
{
    auto f = []
    { cout << "lambda" << endl; };
    f();
}

inline string make_plural(size_t ctr, const string &word,
                          const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a)
                      { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(wc, words.begin(), [&os, c](const string &s)
             { os << s << c; });
    cout << endl;
}

void fcn3()
{
    size_t v1 = 42;
    auto f = [v1]() mutable
    { return ++v1; };
    v1 = 0;
    auto j = f(); // 43
}

void fcn4()
{
    size_t v1 = 42;
    auto f = [&v1]
    { return ++v1; };
    v1 = 0;
    auto j = f(); // 1
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void test6()
{
    using namespace std::placeholders;
    auto check6 = bind(check_size, _1, 6);

    string s = "hello";
    bool b1 = check6(s);
}

ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}

void test7(vector<string> &words, vector<string>::size_type sz, ostream &os = cout, char c = ' ')
{
    using namespace std::placeholders;

    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a)
                      { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    for_each(words.begin(), words.end(), [&os, c](const string &s)
             { os << s << c; });
    cout << endl;

    for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));
}

#include <list>

void test8()
{
    vector<int> iVec{1, 2, 3, 4, 5, 6};
    auto it = iVec.insert(iVec.begin() + 1, 9);
    cout << "insert val:" << *it << endl;
    for_each(iVec.begin(), iVec.end(), [](int i)
             { cout << i << endl; });

    cout << "vec2\n";
    vector<int> iVec2{};
    copy(iVec.begin(), iVec.end(), inserter(iVec2, iVec2.begin()));
    for_each(iVec2.begin(), iVec2.end(), [](int i)
             { cout << i << endl; });

    list<int> ilst3{};
    copy(iVec.begin(), iVec.end(), front_inserter(ilst3));
    for_each(ilst3.begin(), ilst3.end(), [](int i)
             { cout << i << endl; });
}

void test9()
{
    istream_iterator<int> int_it(cin);
    istream_iterator<int> int_eof;
    ifstream in("afile");
    istream_iterator<string> str_it(in);
}

void test10()
{
    vector<int> vec{1, 2, 3, 4, 5, 6};
    cout << "begin\n";
    for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter)
    {
        cout << *r_iter << endl;
    }

    cout << "anti-order\n";
    vector<int> vec2{11, 12, 13, 14, 15, 16};
    sort(vec2.rbegin(), vec2.rend());
    for_each(vec2.cbegin(), vec2.cend(), [](int i)
             { cout << i << endl; });
}

void test11()
{
    string line{"hello, my new life"};
    auto pos = find(line.cbegin(), line.cend(), ',');
    cout << string(line.cbegin(), pos) << endl;

    cout << "reverse:\n";
    auto rcomma = find(line.crbegin(), line.crend(), ',');
    cout << string(line.crbegin(), rcomma) << endl;
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test8();

    // test10();
    test11();
    return 0;
}