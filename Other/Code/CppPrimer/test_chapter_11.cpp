#include <map>
#include <string>
#include <set>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void test1()
{
    map<string, size_t> word_count;
    set<string> exclude = {"The",
                           "But",
                           "And",
                           "Or"};
}

class Sales_data
{
public:
    uint32_t isbn() const
    {
        return isbn_;
    }

private:
    uint32_t isbn_{};
};

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

void test2()
{
    multiset<Sales_data, decltype(compareIsbn) *> bookstore(compareIsbn);
}

pair<string, int> process(vector<string> &v)
{
    if (v.empty())
    {
        // reutrn pair<string, int>();
        return make_pair("", 0);
    }
    else
    {
        return {v.back(), v.back().size()};
    }
}

void test3()
{
    set<string>::value_type v1;
    set<string>::key_type v2;
    static_assert(is_same<decltype(v1), decltype(v2)>(), "why set::key_type != set::value_type");

    map<string, int>::value_type v3;
    static_assert(is_same<decltype(v3), pair<const string, int>>(), "why v3 not expected");
    map<string, int>::key_type v4;
    map<string, int>::mapped_type v5;
    static_assert(is_same<int, decltype(v5)>(), "why mapped_type not expected");
}

void test4()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        auto ret = word_count.insert({word, 1});
        if (!ret.second)
        {
            ++ret.first->second;
        }
    }
}

void test5()
{
    multimap<int, int> mp{};
    mp.insert({1, 2});
    mp.insert(pair<int, int>(2, 4));
    mp.insert(make_pair(3,5));
    mp.insert(multimap<int, int>::value_type(2, 8));

    for (auto [key, value] : mp) {
        cout << "key: " << key << " value: " << value << endl;

        // if (key == 1) {
        //     mp.erase(key); // 会导致segmentation fault
        // }
    }
}

void test6()
{
    map<int, int> m{};
    m.emplace(1, 2);
    // m.emplace_hint(m.end(), 4);

    auto it = m.find(1);
    m.erase(it);

    for (auto &elem : m) {
        cout << elem.first << "-" << elem.second << endl;
    }
}

void test7()
{
    set<int> iset{0, 1, 2, 3, 4, 5, 6, 7};
    auto it = iset.find(1);
    cout << *it << endl;

    it = iset.find(11);
    if (it == iset.end()) {
        cout << "no 11\n";
    }

    cout << "count 1: " << iset.count(1) << endl;
    cout << "count 11: " << iset.count(11) << endl;
}

void test8()
{
    multimap<string, string> authors;
    authors.insert({"Barth, John", "Sot-Weed Factor"});
    authors.insert({"Alain de Botton", "WWho know"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});

    string search_item{"Barth, John"};
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);
    while(entries) {
        cout << iter->second << endl;
        ++iter;
        --entries;
    }
}

map<string, string> buildMap(ifstream &map_file)
{
    return {};
}

// void word_transform(ifstream &map_file, ifstream &input)
// {
//     auto trans_map = buildMap(map_file);
//     string text{};
//     while (getline(input, text)) {
//         istringstream stream(text);
//         string word{};
//         bool firstword = true;
//         while (stream >> word) {
//             if (firstword) {
//                 firstword = false;
//             } else {
//                 cout << " ";
//             }

//             cout << transform(word, trans_map);
//         }
//         cout << endl;
//     }
// }

void test9()
{
    vector<int> ivec{2,4,6,8,2,4,6,8};
    set<int> set2{1};
    set2.insert(ivec.cbegin(), ivec.cend());
    cout << "set2 start\n";
    for (auto i : set2) {
        cout << i << endl;
    }
    cout << "set2 end\n";
}

int main()
{
    // test1();
    // test3();
    // test5();
    // test6();
    // test7();

    // test8();
    test9();
    return 0;
}