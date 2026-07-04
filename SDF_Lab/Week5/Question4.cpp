#include<iostream>
#include<vector>
using namespace std;
class Distance
{
    int kilo;
    int meter;

    public:
    Distance()
    {

    }
    Distance(int k,int m)
    {
        kilo=k;
        meter=m;
    }

    Distance operator+(const Distance &obj)
    {
            Distance temp;
            temp.kilo=kilo+obj.kilo;
            temp.meter = meter+obj.meter;
            if(temp.meter>=1000)
            {
                temp.kilo++;
                temp.meter-=1000;
            }
            return temp;

    }
    Distance operator-(const Distance &obj)
    {
            Distance temp;
            temp.kilo=kilo-obj.kilo;
            temp.meter = meter-obj.meter;
            if(temp.meter<0)
            {
                temp.kilo--;
                temp.meter=1000+temp.meter;
            }
            return temp;

    }
    void display()
    {
        cout<<"Distance is "<<kilo<< "km and "<<meter<<"m."<<endl;
    }
};
int main()
{
    Distance obj1(5,800);
    Distance obj2(3,900);
    Distance obj3,obj4;
    obj3=obj1+obj2;
    obj4=obj1-obj2;
    obj3.display();
    obj4.display();
    return 0;
}