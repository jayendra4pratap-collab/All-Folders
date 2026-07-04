#include <iostream>
using namespace std;
class Area
{
private:
    int l, h;

public:
    Area(int len, int hei)
    {
        l = len;
        h = hei;
    }
    int getArea()
    {
        return l * h;
    }
};

int main()
{
    Area ob1(3, 4);
    Area ob2 = ob1;
    cout << "Area :" << ob2.getArea();
}