#include<iostream>
#include<vector>
using namespace std;
class Product
{
    private : 
    int price;
    int quan;
   

    public:
    Product(int p ,int q)
    {
       price=p;
       quan=q;
        
    }
    friend int CalTotal(Product &obj1,Product &obj2);
};

int CalTotal(Product &obj1,Product &obj2)
{

    return obj1.price*obj1.quan + obj2.price*obj2.quan;
}
int main()
{
    Product obj1(230,5);
    Product obj2(300,3);
    int sum=CalTotal(obj1,obj2);
    cout<<"Sum  is "<<sum;
    return 0;
}