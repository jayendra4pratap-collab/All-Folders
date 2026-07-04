#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 5;
template <typename T>

class GenericContainer
{
private:
    T data[MAX_SIZE];
    int size;

public:
    GenericContainer()
    {
        size = 0;
    }

    void addElement(T val)
    {

        if (size >= MAX_SIZE)
        {
            throw "OverFlow...";
        }
        data[size] = val;
        size++;
    }

    void removeElement(int index)
    {

        if (size == 0)
            throw("Cannot remove from an empty container.");
        if (index < 0 || index > size)
            throw "Invalid Index Entered.";
        for (int i = index; i < size - 1; ++i)
        {
            data[i] = data[i + 1];
        }
        --size;
    }

    T getElement(int index)
    {

        if (index < 0 || index >= size)
            throw "Invalid Index Entered.";

        return data[index];
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        cout << "Container elements: ";
        for (int i = 0; i < size; ++i)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    try
    {
        GenericContainer<int> ob;
        ob.addElement(10);
        ob.addElement(20);
        ob.addElement(30);
        ob.addElement(40);
        ob.addElement(50);
        ob.display();
       // ob.addElement(60);
        ob.removeElement(3);
        ob.display();
       // ob.removeElement(6);
        ob.display();
        cout << ob.getElement(1) << endl;
        ob.display();
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }

    return 0;
}