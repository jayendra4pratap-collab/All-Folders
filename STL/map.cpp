#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    map<string,int> marks;
    marks["Jay"]=86;
    marks["Hello"]=98;
    marks["Mayank"]=94;
    map<string,int> :: iterator ite;
    for(ite=marks.begin();ite!=marks.end();ite++)
    {
        cout<<(*ite).first<<" "<<(*ite).second<<endl;
    }
    return 0;
}