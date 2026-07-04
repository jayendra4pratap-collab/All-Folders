#include <iostream>
#include <ctime>
using namespace std;

// Colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

// Function declarations
void box(int arr[][10]);
void loadPuzzle(int arr[][10], bool fixed[][10], int choice);
bool checkWin(int arr[][10]);
bool isValid(int arr[][10], int row, int col, int num);

int main()
{
    cout << CYAN;
    cout << "\n=================================\n";
    cout << "        SUDOKU GAME 🎮\n";
    cout << "=================================\n";
    cout << RESET;

    int arr[10][10] = {0};
    bool fixed[10][10] = {false};

    int choice;
    do
    {
        cout << "\nSelect Level:\n";
        cout << "1. Easy\n2. Medium\n3. Hard\nEnter choice: ";
        cin >> choice;
    } while (choice < 1 || choice > 3);

    loadPuzzle(arr, fixed, choice);

    int mistakes = 3;
    time_t start = time(0);

    while (!checkWin(arr))
    {
        if (mistakes == 0)
        {
            cout << RED << "\n💀 You lost!\n" << RESET;
            break;
        }

        box(arr);

        int row, col, num;
        cout << "\nEnter move (row col number): ";
        cin >> row >> col >> num;

        if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9)
        {
            cout << RED << "Invalid input!\n" << RESET;
            continue;
        }

        if (fixed[row][col])
        {
            cout << YELLOW << "⚠ Cannot change fixed cell!\n" << RESET;
            continue;
        }

        if (!isValid(arr, row, col, num))
        {
            mistakes--;
            cout << RED << "❌ Wrong move! Remaining: " << mistakes << RESET << endl;
            continue;
        }

        arr[row][col] = num;
        cout << GREEN << "✔ Correct move!\n" << RESET;
    }

    if (checkWin(arr))
    {
        time_t end = time(0);
        box(arr);
        cout << GREEN << "\n🎉 CONGRATULATIONS! 🎉\n";
        cout << "Solved in " << (end - start) << " seconds\n" << RESET;
    }

    return 0;
}

// Display board
void box(int arr[][10])
{
    cout << "\n+-------+-------+-------+\n";
    for (int i = 1; i <= 9; i++)
    {
        cout << "| ";
        for (int j = 1; j <= 9; j++)
        {
            if (arr[i][j] == 0)
                cout << ". ";
            else
                cout << arr[i][j] << " ";

            if (j % 3 == 0)
                cout << "| ";
        }
        cout << endl;

        if (i % 3 == 0)
            cout << "+-------+-------+-------+\n";
    }
}

// Check valid move
bool isValid(int arr[][10], int row, int col, int num)
{
    // Row & Column check
    for (int i = 1; i <= 9; i++)
    {
        if (arr[row][i] == num || arr[i][col] == num)
            return false;
    }

    // 3x3 box check
    int startRow = (row - 1) / 3 * 3 + 1;
    int startCol = (col - 1) / 3 * 3 + 1;

    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (arr[i][j] == num)
                return false;
        }
    }

    return true;
}

// Load puzzles
void loadPuzzle(int arr[][10], bool fixed[][10], int choice)
{
    int t[9][9];

    if (choice == 1) // Easy
    {
        int temp[9][9] = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}};
        memcpy(t, temp, sizeof(t));
    }
    else if (choice == 2) // Medium
    {
        int temp[9][9] = {
            {0,0,5,3,0,0,0,0,0},
            {8,0,0,0,0,0,0,2,0},
            {0,7,0,0,1,0,5,0,0},
            {4,0,0,0,0,5,3,0,0},
            {0,1,0,0,7,0,0,0,6},
            {0,0,3,2,0,0,0,8,0},
            {0,6,0,5,0,0,0,0,9},
            {0,0,4,0,0,0,0,3,0},
            {0,0,0,0,0,9,7,0,0}};
        memcpy(t, temp, sizeof(t));
    }
    else // Hard
    {
        int temp[9][9] = {
            {1,0,0,0,0,7,0,9,0},
            {0,3,0,0,2,0,0,0,8},
            {0,0,9,6,0,0,5,0,0},
            {0,0,5,3,0,0,9,0,0},
            {0,1,0,0,8,0,0,0,2},
            {6,0,0,0,0,4,0,0,0},
            {3,0,0,0,0,0,0,1,0},
            {0,4,0,0,0,0,0,0,7},
            {0,0,7,0,0,0,3,0,0}};
        memcpy(t, temp, sizeof(t));
    }

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            arr[i][j] = t[i - 1][j - 1];
            if (arr[i][j] != 0)
                fixed[i][j] = true;
        }
    }
}

// Check win
bool checkWin(int arr[][10])
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (arr[i][j] == 0)
                return false;
        }
    }
    return true;
}