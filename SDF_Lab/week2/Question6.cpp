#include<iostream>
using namespace std;
class First
{
    string name;
    

    public :
    First(string s)
    {
        name=s;
    }
    void printName()
    {
        cout<<"Name : "<<name;
    }
};
int main()
{
    First obj("Jayendra Pratap Singh");
    obj.printName();
    return 0;
}