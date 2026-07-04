#include<iostream>
#include<vector>
using namespace std;
class Box
{
    private : 
    int length;
    int width;
    int height;

    public:
    Box(int h ,int w,int l)
    {
        length=l;
        height=h;
        width=w;
    }
    friend int addVolume(Box &obj1,Box &obj2);
};

int addVolume(Box &obj1,Box &obj2)
{
    return (obj1.length*obj1.width*obj1.height)+(obj2.length*obj2.width*obj2.height);
}
int main()
{
    Box obj1(2,3,4);
    Box obj2(1,2,3);
    int sum=addVolume(obj1,obj2);
    cout<<"Sum of the volume is "<<sum;
    return 0;
}