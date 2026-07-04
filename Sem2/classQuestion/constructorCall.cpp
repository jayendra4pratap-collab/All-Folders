#include <iostream>
using namespace std;
class Demo
{
public:
    Demo()
    {
        cout << "Constructor\n";
    }
    ~Demo()
    {
        cout << "Destructor\n";
    }
};
    Demo getObj()
    {
        Demo d;
        return d;
    }

int main()
{
    Demo obj = getObj();
    return 0;
}

/*#include <iostream>
using namespace std;
class Sample
{
public:
    Sample()
    {
        cout << "Constructor\n";
    }
    ~Sample()
    {
        cout << "Destructor\n";
    }
};
void func()
{
    Sample s;
}
int main()
{
    func();
    func();
}*/