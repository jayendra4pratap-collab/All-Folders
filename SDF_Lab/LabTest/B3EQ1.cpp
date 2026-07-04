#include<iostream>
#include<cstring>
using namespace std;
class Product
{
    char *name;
    float price;
    static int productCount;

    public :
    Product(){
       
    }
    Product(char *n,float p)
    {
        name=new char [strlen(n)+1];
        strcpy(name,n);
        price=p;
        productCount++;
         cout<<"Product Created Successfully ."<<endl;
    }
    void display()
    {
        cout<<"Product Name : "<<name<<endl
            <<"Price : "<<price<<endl;
    }
    static void displayTotal()
    {
        cout<<"Total Product Count = "<<productCount<<endl;
    }
    int getCount()
    {
        return productCount;
    }
    ~Product()
    {
        cout << "Product " << name << " destroyed." << endl;
        delete[] name;
    }
    friend Product &compare(Product &obj1,Product &obj2);
};
int Product::productCount=0;
Product &compare(Product &obj1,Product &obj2)
{
    if(obj1.price > obj2.price)
    {
        return obj1;
    }
    return obj2;
}
int main()
{
    Product *p1=new Product((char*)"Laptop",55000);
    Product *p2=new Product((char*)"Tablet",35000);
    cout<<"----Product Details ---"<<endl;
    p1->display();
    cout<<"----Product Details ---"<<endl;
    p2->display();

   
    cout<<"Costlier Product Details : "<<endl;
    Product &ob=compare(*p1,*p2);
    ob.display();
    delete p1;
    delete p2;
    return 0;
}