#include<iostream>
using namespace std;
struct Book
{
    string id;
    string title;
    float price;
    
} ;
int main()
{
    int n;
    cout<<"Enter number of books : ";
    cin>>n;
    struct Book b[n];
   
    for(int i=0;i<n;i++)
    {
         cout<<"Enter Details of "<<i+1<<" book : "<<endl;
        cout<<"Enter id : ";
        cin>>b[i].id;
        cout<<"Enter title : ";
        cin>>b[i].title;

        cout<<"Enter price : ";
        cin>>b[i].price;     
    }

    for (int i = 1; i < n; i++)
    {
        int j=i;
        while(j>0&&b[j-1].price >b[j].price)
        {
            struct Book temp=b[j];
            b[j]=b[j-1];
            b[j-1]=temp;
            j--;
        }
       
    }
    cout<<"After Sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Book id : "<<b[i].id<<endl;
        cout<<"Book Title : "<<b[i].title<<endl;
        cout<<"Book price : "<<b[i].price<<endl<<endl;
    }
    return 0;
}
    