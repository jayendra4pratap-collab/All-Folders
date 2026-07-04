#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    map<string,vector<double>> mp;
    mp["ALTO"]={2,4,3};
    mp["Defender"]={4,4.5,4.2};
    mp["BMW"]={4,3,4.6};
    
    string name;
    double maxRating;
    for(auto car : mp)
    {
        double sum=0;
        double size=0;
        for(double rating : car.second)
        {
            size++;
            sum+=rating;
        }
        maxRating = sum/size;
        if(sum>maxRating)
        {
            name=car.first;
        }
    }
    cout<<"Name : "<<name<<endl;
    cout<<"Max Average Rating : "<<maxRating<<endl;
    return 0;
}