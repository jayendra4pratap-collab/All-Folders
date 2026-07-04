#include <iostream>
using namespace std;

void box(int arr[][10]);
void loadPuzzle(int arr[][10], int choice);
bool checkWin(int arr[][10]);
void giveHint(int arr[][10]);
bool isSafe(int arr[][10], int row, int col, int num);
bool solveSudoku(int arr[][10]);

int main()
{
    cout << endl;
    cout << "          #########################" << endl;
    cout << "          #  WELCOME--TO--SUDUKO  #" << endl;
    cout << "          #########################" << endl;
    cout << endl;
    int arr[10][10] = {0};
    arr[0][0] = 0;
    arr[0][1] = 1;
    arr[0][2] = 2;
    arr[0][3] = 3;
    arr[0][4] = 4;
    arr[0][5] = 5;
    arr[0][6] = 6;
    arr[0][7] = 7;
    arr[0][8] = 8;
    arr[0][9] = 9;

    arr[1][0] = 1;
    arr[2][0] = 2;
    arr[3][0] = 3;
    arr[4][0] = 4;
    arr[5][0] = 5;
    arr[6][0] = 6;
    arr[7][0] = 7;
    arr[8][0] = 8;
    arr[9][0] = 9;

    bool flag = true;
    int choice;
    while (flag)
    {
        cout << "Select Level:\n";
        cout << "1. Very Easy\n";
        cout << "2. Easy\n";
        cout << "3. Easy-Medium\n";
        cout << "4. Medium\n";
        cout << "5. Hard\n";
        cout << "6. Very Hard\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (choice < 1 || choice > 6)
        {
            cout << "Invalid Number Entered . " << endl;
            flag = true;
        }
        else
            flag = false;
    }

    loadPuzzle(arr, choice);

    int mistake = 3;

    while (!checkWin(arr))
    {
        if (mistake == 0)
        {
            cout << "You lost." << endl;
            cout << "Well tried...." << endl;
            ;
            break;
        }
        box(arr);
        int row, col, num;
        cout << "Enter row (0 0 0 for hint): ";
        cin >> row;
        cout << "Enter col : ";
        cin >> col;
        cout << "Enter Number : ";
        cin >> num;

        if (row == 0 && col == 0 && num == 0)
        {
            giveHint(arr);
            continue;
        }

        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9)
        {
            cout << "Invalid Input." << endl;
            continue;
        }

        if (arr[row][col] != 0)
        {
            cout << " Already number filled." << endl;
            continue;
        }
        bool check = true;
        for (int i = 1; i <= 9; i++)
        {
            if (arr[row][i] == num)
            {
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
                check = false;
                break;
            }
            if (arr[i][col] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
                break;
            }
        }

        if (!check)
            continue;

        if ((row >= 1 && row <= 3) && (col >= 1 && col <= 3))
        {
            if (arr[1][1] == num || arr[1][2] == num || arr[1][3] == num || arr[2][1] == num || arr[2][2] == num || arr[2][3] == num || arr[3][1] == num || arr[3][2] == num || arr[3][3] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
            }
        }
        else if ((row >= 1 && row <= 3) && (col >= 4 && col <= 6))
        {
            if (arr[1][4] == num || arr[1][5] == num || arr[1][6] == num || arr[2][4] == num || arr[2][5] == num || arr[2][6] == num || arr[3][4] == num || arr[3][5] == num || arr[3][6] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
            }
        }
        else if ((row >= 1 && row <= 3) && (col >= 7 && col <= 9))
        {
            if (arr[1][7] == num || arr[1][8] == num || arr[1][9] == num || arr[2][7] == num || arr[2][8] == num || arr[2][9] == num || arr[3][7] == num || arr[3][8] == num || arr[3][9] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
            }
        }
        else if ((row >= 4 && row <= 6) && (col >= 1 && col <= 3))
        {
            if (arr[4][1] == num || arr[4][2] == num || arr[4][3] == num || arr[5][1] == num || arr[5][2] == num || arr[5][3] == num || arr[6][1] == num || arr[6][2] == num || arr[6][3] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
            }
        }
        else if ((row >= 4 && row <= 6) && (col >= 4 && col <= 6))
        {
            if (arr[4][4] == num || arr[4][5] == num || arr[4][6] == num || arr[5][4] == num || arr[5][5] == num || arr[5][6] == num || arr[6][4] == num || arr[6][5] == num || arr[6][6] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
            }
        }
        else if ((row >= 4 && row <= 6) && (col >= 7 && col <= 9))
        {
            if ((arr[4][7] == num) || arr[4][8] == num || arr[4][9] == num || arr[5][7] == num || arr[5][8] == num || arr[5][9] == num || arr[6][7] == num || arr[6][8] == num || arr[6][9] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
            }
        }
        else if ((row >= 7 && row <= 9) && (col >= 1 && col <= 3))
        {
            if (arr[7][1] == num || arr[7][2] == num || arr[7][3] == num || arr[8][1] == num || arr[8][2] == num || arr[8][3] == num || arr[9][1] == num || arr[9][2] == num || arr[9][3] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
            }
        }
        else if ((row >= 7 && row <= 9) && (col >= 4 && col <= 6))
        {
            if (arr[8][4] == num || arr[8][5] == num || arr[8][6] == num || arr[7][4] == num || arr[7][5] == num || arr[7][6] == num || arr[9][4] == num || arr[9][5] == num || arr[9][6] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
            }
        }
        else
        {
            if (arr[7][7] == num || arr[7][8] == num || arr[7][9] == num || arr[8][7] == num || arr[8][8] == num || arr[8][9] == num || arr[9][7] == num || arr[9][8] == num || arr[9][9] == num)
            {
                check = false;
                cout << " Wrong Number Entered " << endl;
                mistake--;
                cout << mistake << " chances remaining ." << endl;
            }
        }

        if (check)
            arr[row][col] = num;
    }
    return 0;
}

void box(int arr[][10])
{
    cout << "\n";

    cout << "    1 2 3   4 5 6   7 8 9\n";

    for (int i = 1; i <= 9; i++)
    {

        if (i == 1 || i == 4 || i == 7)
            cout << "  +-------+-------+-------+\n";

        cout << i << " | ";

        for (int j = 1; j <= 9; j++)
        {
            if (arr[i][j] == 0)
                cout << ". ";
            else
                cout << arr[i][j] << " ";

            if (j == 3 || j == 6)
                cout << "| ";
        }

        cout << "|\n";
    }

    cout << "  +-------+-------+-------+\n\n";
}

/*void box(int arr[][10])
{
    cout << endl;

    int m = 0, n = 0;
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            if (i == 3 || (4 < j && j < 8) || (((j == 20 || j == 32) && i % 2 == 0)))
            {
                cout << " ";
                continue;
            }
            if ((i == 10 || i == 16) && (j % 2 == 0))
            {
                cout << " ";
                continue;
            }
            if (i % 2 == 0)
                cout << "-";
            else if ((j == 20 || j == 32) && i % 2 != 0)
                cout << "!";
            else if (j % 4 == 0 && i % 2 != 0)
                cout << "|";
            else if (j % 2 != 0 && i % 2 != 0)
                cout << " ";

            else
            {
                if (arr[n][m] == 0)
                    cout << " ";
                else
                {
                    cout << arr[n][m];
                }
                if (j == 43)
                {
                    n++;
                    m = 0;
                }
                else
                {
                    m++;
                }
            }
        }
        cout << endl;
    }
    for (int i = 0; i < 45; i++)
    {
        if (4 < i && i < 8)
            cout << " ";
        else
            cout << "-";
    }
    cout << endl;
    cout << endl;
}*/

void loadPuzzle(int arr[][10], int choice)
{
    int temp[10][10] = {0};
    switch (choice)
    {
    case 1:
    {
        int t[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                temp[i][j] = t[i - 1][j - 1];
            }
        }
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                arr[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 2:
    {
        int t[9][9] = {
            {0, 0, 5, 3, 0, 0, 0, 0, 0},
            {8, 0, 0, 0, 0, 0, 0, 2, 0},
            {0, 7, 0, 0, 1, 0, 5, 0, 0},
            {4, 0, 0, 0, 0, 5, 3, 0, 0},
            {0, 1, 0, 0, 7, 0, 0, 0, 6},
            {0, 0, 3, 2, 0, 0, 0, 8, 0},
            {0, 6, 0, 5, 0, 0, 0, 0, 9},
            {0, 0, 4, 0, 0, 0, 0, 3, 0},
            {0, 0, 0, 0, 0, 9, 7, 0, 0}};
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                temp[i][j] = t[i - 1][j - 1];
            }
        }
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                arr[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 3:
    {
        int t[9][9] = {
            {0, 2, 0, 6, 0, 8, 0, 0, 0},
            {5, 8, 0, 0, 0, 9, 7, 0, 0},
            {0, 0, 0, 0, 4, 0, 0, 0, 0},
            {3, 7, 0, 0, 0, 0, 5, 0, 0},
            {6, 0, 0, 0, 0, 0, 0, 0, 4},
            {0, 0, 8, 0, 0, 0, 0, 1, 3},
            {0, 0, 0, 0, 2, 0, 0, 0, 0},
            {0, 0, 9, 8, 0, 0, 0, 3, 6},
            {0, 0, 0, 3, 0, 6, 0, 9, 0}};
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                temp[i][j] = t[i - 1][j - 1];
            }
        }
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                arr[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 4:
    {
        int t[9][9] = {
            {0, 0, 0, 0, 0, 0, 2, 0, 0},
            {0, 8, 0, 0, 0, 7, 0, 9, 0},
            {6, 0, 2, 0, 0, 0, 5, 0, 0},
            {0, 7, 0, 0, 6, 0, 0, 0, 0},
            {0, 0, 0, 9, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 2, 0, 0, 4, 0},
            {0, 0, 5, 0, 0, 0, 6, 0, 3},
            {0, 9, 0, 4, 0, 0, 0, 7, 0},
            {0, 0, 6, 0, 0, 0, 0, 0, 0}};
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                temp[i][j] = t[i - 1][j - 1];
            }
        }
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                arr[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 5:
    {
        int t[9][9] = {
            {1, 0, 0, 0, 0, 7, 0, 9, 0},
            {0, 3, 0, 0, 2, 0, 0, 0, 8},
            {0, 0, 9, 6, 0, 0, 5, 0, 0},
            {0, 0, 5, 3, 0, 0, 9, 0, 0},
            {0, 1, 0, 0, 8, 0, 0, 0, 2},
            {6, 0, 0, 0, 0, 4, 0, 0, 0},
            {3, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 4, 0, 0, 0, 0, 0, 0, 7},
            {0, 0, 7, 0, 0, 0, 3, 0, 0}};
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                temp[i][j] = t[i - 1][j - 1];
            }
        }
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                arr[i][j] = temp[i][j];
            }
        }
        break;
    }
    case 6:
    {
        int t[9][9] = {
            {0, 0, 0, 0, 0, 0, 0, 1, 2},
            {0, 0, 0, 0, 0, 7, 0, 0, 0},
            {0, 0, 1, 0, 9, 0, 0, 0, 0},
            {0, 0, 0, 5, 0, 0, 4, 0, 7},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 4, 0, 0, 0, 9, 0, 0, 0},
            {0, 0, 0, 0, 7, 0, 3, 0, 0},
            {0, 0, 0, 6, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}};
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                temp[i][j] = t[i - 1][j - 1];
            }
        }
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                arr[i][j] = temp[i][j];
            }
        }
        break;
    }
    default:
        cout << "Invalid Input " << endl;
    }
}

bool checkWin(int arr[][10])
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (arr[i][j] == 0)
            {
                return false;
            }
        }
    }
    box(arr);
    cout << "🎉 Congratulations! You solved the Sudoku!\n"
         << endl;
    return true;
}

bool isSafe(int arr[][10], int row, int col, int num)
{
    for (int i = 1; i <= 9; i++)
        if (arr[row][i] == num)
            return false;

    for (int i = 1; i <= 9; i++)
        if (arr[i][col] == num)
            return false;

    int startRow = row - (row - 1) % 3;
    int startCol = col - (col - 1) % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (arr[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solveSudoku(int arr[][10])
{
    for (int row = 1; row <= 9; row++)
    {
        for (int col = 1; col <= 9; col++)
        {
            if (arr[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(arr, row, col, num))
                    {
                        arr[row][col] = num;

                        if (solveSudoku(arr))
                            return true;

                        arr[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void giveHint(int arr[][10])
{
    int temp[10][10];

    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            temp[i][j] = arr[i][j];

    if (!solveSudoku(temp))
    {
        cout << "No solution exists!\n";
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][j] = temp[i][j];
                cout << "Hint: Filled row " << i
                     << ", col " << j
                     << " with " << temp[i][j] << endl;
                return;
            }
        }
    }

    cout << "No empty cells left!\n";
}