#include <iostream>
#include <cstring>
using namespace std;
class Mobile
{
    long mNum;
    char *name;
    double price;

public:

    Mobile(long m, char *n, double p)
    {
        mNum = m;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        price = p;
    }
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Model Number : " << mNum << endl;
        cout << "Price : " << price << endl;
    }
    double getprice()
    {
        return price;
    }
    void update(int p)
    {
        if (p < 0)
        {
            cout << "Price is 0 , can't be updated" << endl;
            return;
        }
        else
        {
            price = p;
        }
    }
    ~Mobile()
    {

        delete []name;
    }
};
int main()
{
    cout << "Enter number of mobile phones : ";
    int n;
    cin >> n;
    Mobile **mob = new Mobile *[n];
    for (int i = 0; i < n; i++)
    {
        long num;
        char s[100];
        double p;
        cin.ignore();
        cout << "Enter the details of mobile " << i + 1 << ":" << endl
             << "Enter name : ";
        cin.getline(s,100);
        cout << "Enter model number : ";
        cin >> num;
        cout << "Enter price : ";
        cin >> p;
        mob[i]=new Mobile(num, s, p);
    }
    cout << "\nComplete inventory list ;\n" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Mobile phone " << i + 1 << endl;
        mob[i]->display();
    }
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        total += mob[i]->getprice();
    }
    cout << "Total Price :" << total << endl;
    cout << "Avg Price :" << total / n << endl;
    for (int i = 0; i < n; i++)
    {
        delete mob[i];
    }

    delete []mob;
    return 0;
}