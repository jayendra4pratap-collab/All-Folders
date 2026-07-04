#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of student : ";
    cin >> n;
    float *arr=new float[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the CGPA of the "<<i+1<<" student : ";
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"CGPA of "<<i+1<< " student is "<<arr[i]<<endl;
    }
    

    return 0;
}