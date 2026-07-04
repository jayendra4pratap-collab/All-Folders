#include<iostream>
#include<cstring>
using namespace std;

class Billing;     

class Patient{
    char *name;
    int id;
    int days;
    double cost;
    static int total;

    public:
    Patient(){
        cost=0;
        days=0;
        name=nullptr;               //Null pointer
    }
    Patient(char *n,int i,int d,double c)
    {
        name = new char [strlen(n)+1];
        strcpy(name,n);
        id=i;
        days=d;
        cost=c;
        total++;
    }
    Patient(const Patient &ob)
    {
        name=ob.name;
        id=ob.id;
        days=ob.days;
        cost=ob.cost;
    }
     Patient &operator=(const Patient &p)       //use of &  and concept  ********************
    {
        if (this == &p)
            return *this;

        delete[] name;

        id = p.id;
        days = p.days;
        cost = p.cost;

        if (p.name)
        {
            name = new char[strlen(p.name) + 1];
            strcpy(name, p.name);
        }
        else
            name = nullptr;

        return *this;
    }
    void display()
    {
        cout<<"Patient Name : "<<name<<endl
            <<"Patient ID : "<<id<<endl
            <<"Days Admitted : "<<days<<endl
            <<"Total cost : "<<cost <<endl;
    }
    
    friend class Billing;
    ~Patient()
    {
        delete []name;
    }
    
};
class Billing
{
    public :


     static void applyInsurance(Patient *p, int n)
    {
        cout << "Applying Medical Insurance Discount (20%)..." << endl;
        cout << "Updated Patient Bills:" << endl;
        cout << "----------------------" << endl;

        for(int i = 0; i < n; i++)
        {
            p[i].cost = p[i].cost - (p[i].cost * 0.20);

            cout << "Patient Name : " << p[i].name << endl;
            cout << "Updated Bill : " << p[i].cost << endl;
        }

        cout << "Total Patients Admitted: "
             << Patient::total << endl;
    }
};
int Patient ::total=0;
int main()
{
    cout<<"Enter number of the patient : ";
    int n ;
    cin>>n;

    Patient p[n];
    for(int i=0;i<n;i++)
    {
        char name[100] ;
        int id,days;
        double cost;


        cout<<"Patient "<<i+1<<endl;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Id : ";
        cin>>id;
        cout<<"Enter Days admitted : ";
        cin>>days;
        cout<<"Enter total cost : ";
        cin>>cost;

        p[i]=Patient(name,id,days,cost);

    }
    cout<<"Details of all Patient :- "<<endl;
    for(int i=0;i<n;i++)
    {
        p[i].display();
    }
    Billing::applyInsurance(p,n);
    
    return 0;
}