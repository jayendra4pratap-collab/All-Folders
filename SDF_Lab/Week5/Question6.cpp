#include<iostream>
#include<vector>
using namespace std;
class Text
{
    string str;
    public:
    Text()
    {}
    Text(string s)
    {
        str=s;
    }

    Text operator+(Text &obj)
    {
        Text s;
        s.str=str+obj.str;
        return s;
    }
    void display()
    {
        cout<<"Your string is "<<str<<endl;
    }
};
int main()
{
    Text obj("Hello");
    Text obj1("World");
    Text obj2=obj+obj1;
    obj2.display();
    return 0;
}