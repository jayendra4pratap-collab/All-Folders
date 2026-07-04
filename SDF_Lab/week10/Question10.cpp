#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> my_map;

    my_map["Cow"] = 1;
    my_map["Cat"] = 2;
    my_map["Lion"] = 3;

    auto it = my_map.find("Cat");
    if (it != my_map.end())
    {
        cout << "Found Cat with value: " << it->second << endl;
        my_map.erase(it);
    }

    for (auto itr = my_map.begin(); itr != my_map.end(); itr++)
    {
        cout << itr->first << " : " << itr->second << endl;
    }

    return 0;
}