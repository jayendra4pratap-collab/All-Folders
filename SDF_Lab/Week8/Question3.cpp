#include <iostream>
#include <cstring>
using namespace std;

class Room
{
    char *name;

public:
    Room()
    {
        name = NULL;
    }
    Room(char *n)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void display()
    {
        cout << "Room: " << name << endl;
    }
};

class House
{
    char *name;
    Room *rooms;
    int count;

public:
    House(const char *n, int c)
    {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        count = c;
        rooms = new Room[count];

        for (int i = 0; i < count; i++)
        {
            char temp[20];
            cout << "Enter room name: ";
            cin >> temp;

            rooms[i] = Room(temp);
        }
    }

    void display()
    {
        cout << "House: " << name << endl;
        for (int i = 0; i < count; i++)
        {
            rooms[i].display();
        }
    }
};

int main()
{
    //  Composition
    House h((char *)"MyHouse", 2);
    h.display();

    return 0;
}