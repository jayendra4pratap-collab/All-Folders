#include<iostream>
using namespace std;
class Area
{
    int l;
    int b;

    public:
    void setDim()
    {
        cout<<"Enter Length : ";
        cin>>l;
        cout<<"Enter Breadth : ";
        cin>>b;
    }

    void getArea()
    {
        cout<<"Area of the rectangle is "<<l*b;
    }
};
int main()
{
    Area obj;
    obj.setDim();
    obj.getArea();
    return 0;
}