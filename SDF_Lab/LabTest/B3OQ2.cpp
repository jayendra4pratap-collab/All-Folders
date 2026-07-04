#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
class Analyse
{
    char *name;
    int num;
    int *list;

    public : 
    Analyse(){
     
    }
    Analyse(char *n,int number,int*l)
    {
        name=new char [strlen(n)+1];
        strcpy(name,n);
        num=number;
        list=new int[num];
        for(int i=0;i<num;i++)
        {
            list[i]=l[i];
        }
    }

    double analyse()
    {
        int sum=0;
        for (int i = 0; i < num; i++)
        {
            sum+=list[i];
        }
        return sum/num;
        
    }

    double analyse(int drop)
    {
        sort(list,list+num);
        if(drop==1)
        {
            int sum=0;
            if(num==1)
            return -1;
            for(int i=1;i<num;i++)
            {
                sum+=list[i];
            }
            return sum/(num-1);
        }else{
             int sum=0;
        for (int i = 0; i < num; i++)
        {
            sum+=list[i];
        }
        return sum/num;
        }
    }

    double analyse(int drop,int bonus)
    {
        sort(list,list+num);
        if(drop==1)
        {
            int sum=0;
            if(num==1)
            return -1;
            for(int i=1;i<num;i++)
            {
                sum+=list[i]+bonus;
            }
            return sum/(num-1);
        }else{
             int sum=0;
        for (int i = 0; i < num; i++)
        {
            sum+=list[i]+bonus;
        }
        return sum/num;
        }
    }

};
int main()
{
    
    cout<<"Enter number of scores : ";
    int n;
    cin>>n;
    Analyse obj ;
    cout<<"Enter name : ";
    char name[100];
    cin.ignore();
    cin>>name;
    int score[n];
    cout<<"Enter scores :-"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>score[i];
    }
    obj=Analyse(name,n,score);
    cout<<"OUTPUT:-"<<endl;
    cout<<obj.analyse()<<endl;
    cout<<obj.analyse(1)<<endl;
    cout<<obj.analyse(1,10)<<endl;

    return 0;
}