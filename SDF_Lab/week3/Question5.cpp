#include <iostream>
using namespace std;
class Print
{
    char *s;
    int size;

public:
    Print(char *str)
    {
        s = str;
        size = sizeof(s);
    }
    Print(const Print &obj)
    {
        size=obj.size;
        s=obj.s;
    }
    ~Print()
    {
        
        cout << "Destructor called" << endl;
    }
    void display()
    {
        cout << "String:" << s << endl;
    }
};

int main()
{
    Print obj1("Jay");
    Print obj2 = obj1;
    obj1.display();
    obj2.display();
    return 0;
}