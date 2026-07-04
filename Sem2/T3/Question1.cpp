#include <iostream>
const int row = 3;
const int col = 3;
using namespace std;
class Matrix
{
    int matrix[row][col];
    static int count;

public:
    Matrix()
    {
        count++;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    Matrix(int arr[row][col])
    {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                matrix[i][j] = arr[i][j];

        count++;
    }

    Matrix operator+(Matrix &m)
    {
        Matrix res ;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.matrix[i][j] = matrix[i][j]+m.matrix[i][j];
            }
        }
        return res;
    }

    Matrix operator+(int val)
    {
        Matrix res;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                res.matrix[i][j] =matrix[i][j]+ val;
            }
        }
        return res;
    }
    void getSize() const
    {
        cout << "Matrix size: " << row << " x " << col << endl;
    }

    static int getCount()
    {
        return count;
    }
    friend void display(const Matrix &arr);
};
int Matrix::count = 0;
void display(const Matrix &m)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << m.matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[][col] = {{2, 3}, {3, 4}};
    int arr1[row][col] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr2[row][col] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    Matrix m1(arr1);
    Matrix m2(arr2);
    Matrix m3;
    cout << "Matrix 1:\n";
    display(m1);
    cout << "Matrix 2:\n";
    display(m2);
    Matrix m4 = m1+m2;
    cout << "Matrix 1 + Matrix 2:\n";
    display(m4);
    Matrix m5 = m1+10;
    cout << "Matrix 1 + Scalar 10:\n";
    display(m5);
    // Matrix size
    m1.getSize();
    // Object count
    cout << "Number of Matrix objects created: " << Matrix::getCount() << endl;
    return 0;
}