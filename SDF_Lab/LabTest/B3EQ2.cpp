#include<iostream>
#include<cstring>
using namespace std;
class SurvivalData
{
    int month;
    int cost;

    public:
    SurvivalData(){

    }
    SurvivalData(int m,int c)
    {
        month=m;
        cost=c;
    }

    SurvivalData operator+(SurvivalData &ob){
        SurvivalData temp;
        temp.month = month+ob.month;
        temp.cost = cost+ob.month;
        return temp;
    }

    bool operator>(SurvivalData &ob)
    {
        if(cost>ob.cost)
        return true;

        return false;
    }
    friend ostream &operator<<(ostream &out,SurvivalData &ob);
};

ostream &operator<<(ostream &out,SurvivalData &ob)
{
    out<<"Survival Month :"<<ob.month<<" months"<<endl;
    out<<"Cost :"<<ob.cost<<endl;
    return out;
}
int main()
{
    SurvivalData ob1(24,50000);
    SurvivalData ob2(18,40000);
    SurvivalData ob = ob1+ob2;
    cout<<ob1;
    cout<<ob2;
    cout<<"Combined data : ";
    cout<<ob;
    if(ob1>ob2)
    cout<<"PAtient 1 has higher cost."<<endl;;
    return 0;
}