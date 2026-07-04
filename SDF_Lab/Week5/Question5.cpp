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

    void cal()
    {
        if(meter>1000)
        {
            kilo+= ( meter/1000);
            meter = meter - (meter/1000)*1000;
        }
    }

     friend istream& operator>>(istream&, Distance&);
    friend ostream& operator<<(ostream&, const Distance&);

};

istream& operator>>(istream& input, Distance& d)  //READ WHY NOT INSIDE THE CLASS
{
    cout << "Enter kilometers : ";
    input >> d.kilo;

    cout << "Enter meters : ";
    input >> d.meter;

    d.cal();

    return input;
}

ostream& operator<<(ostream& out, const Distance& d)
{
    out << "Distance is " << d.kilo << " km and " << d.meter << " m."<<endl;
    return out;
}

int main(){
    Distance obj1,obj2;
    cin>>obj1;
    cin>>obj2;
    cout<<obj1;
    cout<<obj2;
    
   
    return 0;
}