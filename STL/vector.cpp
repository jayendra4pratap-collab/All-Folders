#include<iostream>
#include<vector>
using namespace std;

template <class T>
void display(vector<T>  v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> v;
    int element;
    for(int i=0;i<3;i++)
    {
        cout<<"Enter element of the vector : ";
        cin>>element;
        v.push_back(element);
        
    }
    v.pop_back();

    display(v);
    
    vector<int> :: iterator ite =v.begin();
    v.insert(ite+1,345);          // copies   v.insert(ite+1,50,345);
    display(v);

    vector<char> vec1(5,'a');
    display(vec1);


    return 0;
}
