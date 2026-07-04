
#include <iostream>
using namespace std;
class Book
{
    string isbn;
    string title;
    double price;
    bool status;

public:
    Book()
    {}
    Book(string i,string t,double p,bool avai)
    {
        isbn=i;
        title=t;
        price=p;
        status=avai;
    }

    bool operator==(Book &b)
    {
        if(isbn==b.isbn)
        {
            cout<<"Book "<<title<< "and "<<b.title<<" have same isbn number."<<endl;
            return true;
        }
        return false;
    }

    void operator<(Book &b)
    {
        if(price<b.price)
        cout<<"Book "<< title <<" has lesser price .";
        else if(price ==b.price)
        cout<<"Books have same price .";
        else
        cout<<"Book "<<b.title<<"has lesser price . ";

    }

    void operator!()
    {
        if(status)
        cout<<"Book "<<title<<"is available.";
        else
        cout<<"Book "<<title <<" is not available.";
    }
    
     void display() const
    {
        cout << "ISBN: " << isbn
             << ", Title: " << title
             << ", Price: " << price
             << ", Status: ";

        if (!status)
            cout << "Not available";
        else
            cout << "Available";

        cout << endl;
    }
};
int main()
{
    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book books[100];   
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        string isbn, title;
        double price;
        bool available;

        cout << "\nEnter ISBN: ";
        cin >> isbn;

        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter availability (1 = available, 0 = not available): ";
        cin >> available;

        Book newBook(isbn, title, price, available);

        // check duplicate ISBN
        bool duplicate = false;
        for (int j = 0; j < count; j++)
        {
            if (books[j] == newBook)
            {
                duplicate = true;
                break;
            }
        }

        if (duplicate)
        {
            cout << "Duplicate ISBN found. Book not added.\n";
        }
        else
        {
            books[count] = newBook;
            count++;
        }
    }

    cout << "\nBook list:\n";
    for (int i = 0; i < count; i++)
    {
        books[i].display();
    }

    return 0;
}


