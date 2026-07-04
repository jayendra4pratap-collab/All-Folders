#include <iostream>
using namespace std;

class Vector
{
    float *v;
    int size;

public:
    void create(int n)
    {
        size = n;
        v = new float[size];
        for (int i = 0; i < size; i++)
            cin >> v[i];
    }

    void addScalar(float s)
    {
        for (int i = 0; i < size; i++)
            v[i] += s;
    }

    void multiplyScalar(float s)
    {
        for (int i = 0; i < size; i++)
            v[i] *= s;
    }

    void display()
    {
        cout << "(";
        for (int i = 0; i < size; i++)
        {
            cout << v[i];
            if (i != size - 1)
                cout << ", ";
        }
        cout << ")";
    }

    ~Vector()
    {
        delete[] v;
    }
};

int main()
{
    Vector vec;
    int n;
    cin >> n;

    vec.create(n);
    vec.addScalar(5);
    vec.multiplyScalar(2);
    vec.display();

    return 0;
}