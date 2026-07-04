#include<iostream>
#include<cstring>
using namespace std;
class student {
    int roll;
    char *name;
    int marks;
    string status;

    public : 
    student(){}
    student(int r,char *n,int m,string s)
    {
        roll=r;
        name=new char[strlen(n)+1];
        strcpy(name,n);
        marks=m;
        status=s;
    }

    int getRoll()
    {
        return roll;
    }
    void operator>(student &obj)
    {
        if(marks>obj.marks)
        {
            cout<<name<<" has greator marks ."<<endl;
        }else{
            cout<<obj.name<<" has greator marks ."<<endl;
        }
    }

    bool operator&&(student &obj)
    {
        if( (status == obj.status )&& status=="Pass")
        return true;

        return false;
    }

    friend ostream &operator<<(ostream &out,student &);
};

 ostream &operator<<(ostream &out,student &s)
{
    out<<"Name : "<<s.name<<endl
        <<"Roll NUmber : "<<s.roll<<endl
        <<"Marks : "<<s.marks<<endl
        <<"Status : "<<s.status<<endl;
        return out;

    
}
int main()
{
    int n;
    cout<<"Enter. number of the student : ";
    cin>>n;
    student s[n];
    int count=0;
    while(count<n)
    {
        int roll;
        char name[100];
        int marks;
        string status;
        cout<<"Enter roll number : ";
        cin>>roll;
        cin.ignore();
        cout<<"Enter name : ";
        cin>>name;
        cout<<"Enter marks : ";
        cin>>marks;
        cin.ignore();
        cout<<"Enter status : ";
        cin>>status;
        bool check=true;
        for(int i =0;i<count;i++)
        {
            if(s[i].getRoll()==roll)
            {
                check=false;
                cout<<"Same roll number already entered . Try again!!"<<endl;
                break;
            }
       
        }
        if(check)
        {
            
             s[count]=student(roll,name,marks,status);
             count++;
        }

    }
    cout<<"All Student details :-"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<s[i];
    }




    return 0;
}