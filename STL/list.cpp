#include<iostream>
#include<list>
using namespace std;
void display(list<int> it);
int main()
{
    list<int> list1;     // 0 length
    list<int> list2(5);   // 5 length
    list1.push_back(2);
    list1.push_back(4);
    list1.push_back(6);
    list1.push_back(8);
    list1.push_back(10);

    list<int> :: iterator ite= list1.begin();
    cout<<*ite<<" ";
    display(list1);
    return 0;
}
void display(list<int> it)
{
     list<int> :: iterator ite;
    for(ite=it.begin();ite !=it.end();ite++)
    {
        cout<<*ite<<" ";
    }
}