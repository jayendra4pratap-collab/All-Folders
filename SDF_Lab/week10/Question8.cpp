#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> m;

    m.insert({1,10});
    m.insert({2,20});
    m.insert({3,30});
    m.insert({5,6});

    m.insert_or_assign(2, 99);  // m[2]=99;
    m.insert_or_assign(4, 40);

    for (map<int,int>:: iterator itr = m.begin(); itr != m.end(); itr++)
    {
        cout << "Key: " << itr->first << " Value: " << itr->second << endl;
    }

    return 0;
}