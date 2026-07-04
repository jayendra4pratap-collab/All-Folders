#include <iostream>
#include <vector>
using namespace std;
template <class T>
class MyVector
{
    T *arr;
    int capacity;
    int current;

public:
    MyVector(int size = 1)
    {
        capacity = size;
        current = 0;
        arr = new T[capacity];
    }

    ~MyVector()
    {
        delete[] arr;
    }

    void push_back(T data)
    {
        if (current == capacity)
        {
            T *temp = new T[2 * capacity];

            for (int i = 0; i < capacity; i++)
            {
                temp[i] = arr[i];
            }

            delete[] arr;
            arr = temp;
            capacity *= 2;
        }

        arr[current] = data;
        current++;
    }

    void pop_back()
    {
        if (current > 0)
        {
            current--;
        }
        else
        {
            cout << "Vector is empty!" << endl;
        }
    }

    int size()
    {
        return current;
    }

    void print()
    {
        for (int i = 0; i < current; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    MyVector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.print();
    cout << v.size() << endl;

    v.pop_back();

    v.print();
    cout << v.size() << endl;

    return 0;
}