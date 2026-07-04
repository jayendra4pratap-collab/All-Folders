#include<iostream>
#include<vector>
using namespace std;
class Shape
{
    public:
   virtual void draw(){
        cout<<"Shape"<<endl;
    }
};
class Circle : public Shape
{
    public:
    void draw()
    {
        cout<<"Circle"<<endl;
    }
};
class Rectangle : public Shape
{
    public:
    void draw()
    {
        cout<<"Rectangle"<<endl;
    }
};
int main()
{
    Circle c;
    Rectangle r;
    Shape *s;
    s=&c;
    s->draw();
     s=&r;
    s->draw();
    return 0;
}