#include <iostream>
#include <string>
using namespace std;

void print(char arr[]);
bool check(char arr[]);

int main()
{
    cout << "\t\t !! Welcome to TIC TAC TOE Game !! ";

    a:
    cout << "\nEnter player 1 name : ";
    string name1;
    cin >> name1;

    cout << "Enter player 2 name : ";
    string name2;
    cin >> name2;

    cout << name1 << " (Player 1) , your symbol is 'X' .\n";
    cout << name2 << " (Player 2) , your symbol is 'O' .\n";

    char arr[] = {'1','2','3','4','5','6','7','8','9'};
    print(arr);

    int count = 0;

    while (true)
    {
        int index;
        cout << "\n" << name1 << " ,select your choice(index number) : ";
        cin >> index;

        arr[index - 1] = 'X';
        count++;
        print(arr);

        if (check(arr))
        {
            cout << "\nHURRAY !! \n" << name1 << " Wins !!";
            break;
        }

        if (count == 9)
        {
            cout << "\nHey ! No One wins";
            cout << "\nEnter 'YES' to play again and 'NO' to exit : ";

            string str;
            cin >> str;

            if (str == "Yes" || str == "yes" || str == "YES")
                goto a;
            else
            {
                cout << "Thank you.... Have a nice day!!!";
                break;
            }
        }

        int index1;
        cout << "\n" << name2 << " ,select your choice(index number) : ";
        cin >> index1;

        arr[index1 - 1] = 'O';
        count++;
        print(arr);

        if (check(arr))
        {
            cout << "\nHURRAY !! \n" << name2 << " Wins !!";
            break;
        }
    }
}

bool check(char arr[])
{
    if (arr[0] == arr[1] && arr[1] == arr[2] ||
        arr[3] == arr[4] && arr[4] == arr[5] ||
        arr[6] == arr[7] && arr[7] == arr[8] ||
        arr[0] == arr[3] && arr[3] == arr[6] ||
        arr[1] == arr[4] && arr[4] == arr[7] ||
        arr[2] == arr[5] && arr[5] == arr[8] ||
        arr[0] == arr[4] && arr[4] == arr[8] ||
        arr[2] == arr[4] && arr[4] == arr[6])
    {
        return true;
    }
    return false;
}

void print(char arr[])
{
    int n = 3;
    int num = 0;

    while (n-- > 0)
    {
        for (int i = 0; i < 22; i++)
            cout << "-";

        cout << "\n";

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 22; j++)
            {
                if (i == 1 && (j == 3 || j == 10 || j == 17))
                    cout << arr[num++];
                else if (j == 0 || j == 7 || j == 14 || j == 21)
                    cout << "⎸";
                else
                    cout << " ";
            }
            cout << "\n";
        }
    }

    for (int i = 0; i < 22; i++)
        cout << "-";
}