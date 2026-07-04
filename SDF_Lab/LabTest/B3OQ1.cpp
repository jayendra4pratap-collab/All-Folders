#include<iostream>
#include<vector>
using namespace std;
class Order
{
    int item;
    int *prices;
    int tax;
    int discount;

    public : 
    Order(){}
    Order(int i,int *p,int t,int d)
    {
        item =i;
        prices=new int[i];
        for (int j = 0; j < item; j++)
        {
            prices[j]=p[j];
        }
        
        tax=t;
        discount=d;
    }
    friend class Billing;
};
class Billing :public Order
{
    int charge;
    int distance;

    public: 
    Billing(){}
    Billing(int i,int *p,int t,int d,int c,int dis):charge(c),distance(dis), Order(i,p,t,d)
    {

    }

    void compute()
    {
        double totalcost = 0,netpayable=0;
        for(int i=0;i<item;i++)
        {
            totalcost+=prices[i];
        }
        double totaldilivary =charge*distance;
        netpayable =totalcost+tax+totaldilivary-discount;
        cout<<"---------Final Bill-----------"<<endl;
        cout<<"Total item cost : "<<totalcost<<endl
            <<"Tax : "<<tax<<endl
            <<"Dilivery Charges : "<<totaldilivary<<endl
            <<"Net Payable : "<<netpayable<<endl;

    }  

};
int main()
{
    int n;
    cout<<"Ente number of the order: ";
    cin>>n;

    Billing bill[n];

    for(int i=0;i<n;i++)
    {
        int item;
    int *prices;
    int tax;
    int discount;
     int charge;
    int distance;

        cout<<"Enter the details for the order "<<i+1<<endl;
        cout<<"Enter number of the item : ";
        cin>>item;
         prices =new int[item];
         cout<<"Enter item prices : "<<endl;
         for(int i=0;i<item;i++)
         {
            cin>>prices[i];
         }
         cout<<"Enter Tax : ";
         cin>>tax;
         cout<<"Enter Discount : ";
         cin>>discount;
         cout<<"Enter Dilivery charges : ";
         cin>>charge;
         cout<<"Enter Delivery Distance : ";
         cin>>distance;

         bill[i]=Billing(item,prices,tax,discount,charge,distance);

    }

    for(int i=0;i<n;i++)
    {
        cout<<"Bill for Order "<<i+1<<endl<<endl;
        bill[i].compute();
        cout<<endl;
    }
    
    return 0;
}
/*#include <iostream>
using namespace std;

class DeliveryDetails;   // forward declaration

class OrderDetails
{
private:
    int itemCount;
    int *prices;
    double tax;
    double discount;

    static int totalOrders;

public:
    OrderDetails(int n, int *p, double t, double d)
    {
        itemCount = n;
        tax = t;
        discount = d;

        prices = new int[itemCount];
        for (int i = 0; i < itemCount; i++)
            prices[i] = p[i];

        totalOrders++;
    }

    double getTotalItemCost() const
    {
        double sum = 0;
        for (int i = 0; i < itemCount; i++)
            sum += prices[i];
        return sum;
    }

    double getTax() const
    {
        return tax;
    }

    double getDiscount() const
    {
        return discount;
    }

    static int getTotalOrders()
    {
        return totalOrders;
    }

    friend class DeliveryDetails;

    ~OrderDetails()
    {
        delete[] prices;
    }
};

int OrderDetails::totalOrders = 0;


class DeliveryDetails
{
private:
    double chargePerKm;
    double distance;

public:
    DeliveryDetails(double c, double d)
    {
        chargePerKm = c;
        distance = d;
    }

    void generateBill(const OrderDetails &o) const
    {
        double totalItemCost = o.getTotalItemCost();
        double deliveryCharge = chargePerKm * distance;

        double netAmount =
            totalItemCost + o.getTax() + deliveryCharge - o.getDiscount();

        cout << "------------- Final Bill -------------\n";
        cout << "Total Item Cost : " << totalItemCost << endl;
        cout << "Tax             : " << o.getTax() << endl;
        cout << "Delivery Charge : " << deliveryCharge << endl;
        cout << "Discount        : " << o.getDiscount() << endl;
        cout << "Net Payable     : " << netAmount << endl;
    }
};


int main()
{
    int n;
    cout << "Enter number of orders: ";
    cin >> n;

    OrderDetails **orders = new OrderDetails*[n];
    DeliveryDetails **delivery = new DeliveryDetails*[n];

    for (int i = 0; i < n; i++)
    {
        int items;
        double tax, discount;
        double charge, distance;

        cout << "\nEnter details for Order " << i + 1 << endl;

        cout << "Enter number of items: ";
        cin >> items;

        int *prices = new int[items];
        cout << "Enter item prices:\n";
        for (int j = 0; j < items; j++)
            cin >> prices[j];

        cout << "Enter tax: ";
        cin >> tax;

        cout << "Enter discount: ";
        cin >> discount;

        cout << "Enter delivery charge per km: ";
        cin >> charge;

        cout << "Enter distance: ";
        cin >> distance;

        orders[i]   = new OrderDetails(items, prices, tax, discount);
        delivery[i] = new DeliveryDetails(charge, distance);

        delete[] prices;   // temporary array
    }

    cout << "\n=========== BILL SUMMARY ===========\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nOrder " << i + 1 << endl;
        delivery[i]->generateBill(*orders[i]);
    }

    cout << "\nTotal number of orders processed: "
         << OrderDetails::getTotalOrders() << endl;

    for (int i = 0; i < n; i++)
    {
        delete orders[i];
        delete delivery[i];
    }

    delete[] orders;
    delete[] delivery;

    return 0;
}*/