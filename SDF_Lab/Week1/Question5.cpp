#include <iostream>
using namespace std;

struct Laptop
{
    string brand;
    int RAM;        
    float price;
};

int main()
{
    struct Laptop *ptr;
    cout << "Enter Laptop Brand: ";
    cin >> ptr->brand;

    cout << "Enter RAM (in GB): ";
    cin >> ptr->RAM;

    cout << "Enter Price: ";
    cin >> ptr->price;

   
    ptr->RAM = ptr->RAM + 8;        
    ptr->price = ptr->price + 5000; 

    
    cout << "\nUpdated Laptop Details:\n";
    cout << "Brand: " << ptr->brand << endl;
    cout << "RAM: " << ptr->RAM << " GB" << endl;
    cout << "Price: " << ptr->price << endl;

    return 0;
}