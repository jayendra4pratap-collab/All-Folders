#include<iostream>
#include<forward_list>
using namespace std;

int main()
{
    forward_list<int> l;
    l.push_front(1);
   
    l.push_front(3);
    l.emplace_front(4);
    auto it =l.insert_after(l.begin(),7);
    it=l.insert_after(it,{8,9});
    l.erase_after(it);
    l.reverse();
    l.sort();
   // l.assign({5});
    for(int &x : l)
    {
        cout<<x<<" ";
    }
    return 0;
}