#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> dl = {1, 2, 3};
    list<int>::iterator it = dl.begin();
    advance(it, 2);
    dl.insert(it, 5); // now still it points to 3
    dl.insert(it, 8);
    

    dl.push_back(9);
    dl.push_front(4);
   // dl.sort();

    for (int &x : dl)
        cout << x << " ";
    cout<<endl;

    list<int> list1={5,8,9};
    list<int> list2={3,4,7};
    list <int> :: iterator itr = list1.begin();
    advance(itr,3);
    //list1.splice(itr,list2);
    auto itt = list2.begin();
   // list1.splice(itr,list2,itt);
   list1.merge(list2);
    for (int &x : list1)
        cout << x << " ";
    cout<<endl;
    return 0;
}