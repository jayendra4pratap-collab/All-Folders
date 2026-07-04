#include<iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
void calculate(struct Rectangle rec)
{
    cout<<"Area of Rectangle = "<<rec.length*rec.breadth<<endl
    <<"Perimeter of rectangle = "<<2*(rec.length+rec.breadth);
}


int main()
{
    struct Rectangle rec;
    cout<<"Enter length  :";
    cin>>rec.length;
    cout<<"Enter breadth  :";
    cin>>rec.breadth ;
    calculate(rec);
    return 0;
}