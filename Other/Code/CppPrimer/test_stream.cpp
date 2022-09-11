// stream

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

void test_istringstream()
{
    string line, word;
    vector<PersonInfo> people;
    while (getline(cin, line))
    {
        PersonInfo info;
        string word;
        istringstream record(line);
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }

        people.push_back(info);
    }
}
