#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

#define RED_DOT "\033[31m•\033[0m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

void box(int arr[][10]);
void loadPuzzle(int arr[][10], int choice);
bool checkWin(int arr[][10]);
void giveHint(int arr[][10], int row, int col);
bool isSafe(int arr[][10], int row, int col, int num);
bool solveSudoku(int arr[][10]);
int original[10][10];

void print(char arr[]);
bool check(char arr[]);
bool valid(char arr[], int index);

void printGrid(vector<vector<int>> &grid);
bool isSolved(vector<vector<int>> &grid);
bool isSolvable(vector<int> &arr);
vector<vector<int>> generateHardGrid();
vector<vector<int>> generateMediumGrid();
pair<int, int> findTile(vector<vector<int>> &grid, int val);
pair<int, int> findZero(vector<vector<int>> &grid);

const int HEIGHT = 12;
const int WIDTH = 28;
void clearScreen();
void draw();
void input();
void moveGhost();
void nextLevelMessage();
void logic();
char maze[HEIGHT][WIDTH + 1] = {
    "###########################",
    "#     #         #       ##",
    "# ### # ######  # ####   #",
    "# #       #        #     #",
    "# # ##### # ###### # ### #",
    "#   #     #      # # #   #",
    "### # ########## # # ### #",
    "#   #        #   #       #",
    "# ####### ## # ######### #",
    "#         ##           * #",
    "#                         #",
    "###########################"};
int pacX = 4, pacY = 10;
int ghostX = 22, ghostY = 10;
int score = 0;
int level = 1;
bool gameOver = false;

int main()
{
    cout << CYAN;
    cout << endl;
    cout << "          #############################" << endl;
    cout << "          #  WELCOME  TO  MINDMATRIX  #" << endl;
    cout << "          #############################" << endl;
    cout << endl;
    cout << "Which Game do you want to play :\n " << endl;
    cout << "1 : SUDUKO" << endl;
    cout << "2 : SLIDING PUZZLE GAME" << endl;
    cout << "3 : PACMAN" << endl;
    cout << "4 : TIC-TAE-TOE\n"
         << endl;
    int choice;
    cout << "Enter your choice : ";
    cin >> choice;

    cout << RESET;
    switch (choice)
    {
    case 1:
    {
        cout << GREEN;
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
                cout << RED << "Invalid Number Entered . " << GREEN << endl;
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
                cout << RED << "You lost." << GREEN << endl;
                cout << "Well tried...." << endl;
                break;
            }
            box(arr);
            int row, col, num;
            cout << "Enter row (or Press 0 for hint): ";
            cin >> row;

            if (row == -1)
            {
                break;
            }
            if (row == 0)
            {
                cout << "For Hint" << endl;
                cout << "Enter row : ";
                cin >> row;
                cout << "Enter col : ";
                cin >> col;
                if (row < 1 || row > 9 || col < 1 || col > 9)
                {
                    cout << RED << "Invalid Input." << GREEN << endl;
                    continue;
                }
                giveHint(arr, row, col);
                continue;
            }

            cout << "Enter col : ";
            cin >> col;
            cout << "Enter Number : ";
            cin >> num;

            if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9)
            {
                cout << RED << "Invalid Input." << GREEN << endl;
                continue;
            }

            if (arr[row][col] != 0)
            {
                cout << RED << " Already number filled." << GREEN << endl;
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
        cout << RESET;
    }

    break;

    // Slidding Puzzle Game
    
    case 2:
    {
        srand(time(0));

        int level;
        cout << "Select Level:\n1. Medium\n2. Hard\nChoice: ";
        cin >> level;

        vector<vector<int>> grid;

        if (level == 1)
            grid = generateMediumGrid();
        else
            grid = generateHardGrid();

        cout << "\nCommands:\n";
        cout << "Enter: number + direction (W/A/S/D)\n";
        cout << "R = Reset, Q = Quit\n";

        while (true)
        {
            printGrid(grid);

            if (isSolved(grid))
            {
                cout << "Huraahhh... Puzzle Solved!\n";
                break;
            }

            cout << "Enter move: ";
            string input;
            cin >> input;
            if (input == "-1")
            {
                break;
            }
            if (input == "Q" || input == "q")
                break;

            if (input == "R" || input == "r")
            {
                if (level == 1)
                    grid = generateMediumGrid();
                else
                    grid = generateHardGrid();
                continue;
            }

            if (input.length() < 2)
            {
                cout << "Invalid input!\n";
                continue;
            }

            int num = input[0] - '0';
            char dir = input[1];

            if (num < 1 || num > 8)
            {
                cout << "Invalid tile!\n";
                continue;
            }

            pair<int, int> p = findTile(grid, num);

            int x = p.first;

            int y = p.second;

            int nx = x, ny = y;

            if (dir == 'W' || dir == 'w')
                nx--;
            else if (dir == 'S' || dir == 's')
                nx++;
            else if (dir == 'A' || dir == 'a')
                ny--;
            else if (dir == 'D' || dir == 'd')
                ny++;
            else
            {
                cout << "Invalid direction!\n";
                continue;
            }

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && grid[nx][ny] == 0)
            {
                swap(grid[x][y], grid[nx][ny]);
            }
            else
            {
                cout << "Invalid move!\n";
            }
        }
    }
    break;

    // Pacman
    case 3:
        cout << BLUE;
        {
            srand(time(0));

            while (!gameOver)
            {
                draw();
                input();
                logic();
            }

            // If player loses
            if (score < 30)
            {
                clearScreen();

                cout << "======================" << endl;
                cout << "      GAME OVER       " << endl;
                cout << "======================" << endl;

                cout << "Final Score : " << score << endl;
                cout << "Final Level : " << level << endl;
            }
        }

        break;

    // Tic Tac Toe
    case 4:
    {
        cout << RED;
        cout << "\n\t\t !! Welcome to TIC TAC TOE Game !!\n ";

    a:
        cout << "\nEnter player 1 name : ";
        string name1;
        cin >> name1;

        cout << "Enter player 2 name : ";
        string name2;
        cin >> name2;

        cout << name1 << " (Player 1) , your symbol is 'X' .\n";
        cout << name2 << " (Player 2) , your symbol is 'O' .\n";

        char arr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        print(arr);

        int count = 0;

        while (true)
        {
            int index;
            cout << "\n"
                 << name1 << " ,select your choice(index number) : ";
            cin >> index;

            if (!valid(arr, index))
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            arr[index - 1] = 'X';
            count++;
            print(arr);

            if (check(arr))
            {
                cout << "\nHURRAY !! \n"
                     << name1 << " Wins !!";
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
            cout << "\n"
                 << name2 << " ,select your choice(index number) : ";
            cin >> index1;

            if (!valid(arr, index1))
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            arr[index1 - 1] = 'O';
            count++;
            print(arr);

            if (check(arr))
            {
                cout << "\nHURRAY !! \n"
                     << name2 << " Wins !!";
                break;
            }
        }
    }
        cout << RESET;
        break;

    default:
        cout << "Invalid Input." << endl;
    }
    return 0;
}

// Functions----




//SUDOKU
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
            {
                cout << ". ";
            }
            else if (original[i][j] != 0)
            {
                cout << RED << arr[i][j] << " " << GREEN;
            }
            else
            {
                cout << BLUE << arr[i][j] << " " << GREEN;
            }

            if (j == 3 || j == 6)
                cout << "| ";
        }

        cout << "|\n";
    }

    cout << "  +-------+-------+-------+\n\n";
}

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
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            original[i][j] = arr[i][j];
        }
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
    cout << BLUE << "🎉 Congratulations! You solved the Sudoku!\n"
         << RED << endl;
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

void giveHint(int arr[][10], int row, int col)
{
    int temp[10][10];

    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            temp[i][j] = arr[i][j];

    if (!solveSudoku(temp))
    {
        cout << BLUE << "No solution exists! Prior you have wrong filled\n"
             << GREEN;
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (row == i && col == j)
            {
                arr[i][j] = temp[i][j];
                cout << BLUE << "Hint: Filled row " << i
                     << ", col " << j
                     << " with " << temp[i][j] << GREEN << endl;
                return;
            }
        }
    }

    cout << "No empty cells left!\n";
}




// Slidding Puzzle Game
void printGrid(vector<vector<int>> &grid)
{
    cout << "\n";
    for (auto &row : grid)
    {
        for (auto &val : row)
        {
            if (val == 0)
                cout << "  ";
            else
                cout << GREEN << val << RESET << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

bool isSolved(vector<vector<int>> &grid)
{
    int count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 2 && j == 2 && grid[i][j] == 0)
                return true;
            if (grid[i][j] != count++)
                return false;
        }
    }
    return true;
}

bool isSolvable(vector<int> &arr)
{
    int inv = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (arr[i] && arr[j] && arr[i] > arr[j])
                inv++;
        }
    }
    return (inv % 2 == 0);
}

vector<vector<int>> generateHardGrid()
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    do
    {
        shuffle(arr.begin(), arr.end(), default_random_engine(time(0)));
    } while (!isSolvable(arr));

    vector<vector<int>> grid(3, vector<int>(3));
    int k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = arr[k++];

    return grid;
}

vector<vector<int>> generateMediumGrid()
{
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}};

    int zx = 2, zy = 2;

    int moves = 5 + rand() % 2;
    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    pair<int, int> lastMove = {0, 0};

    for (int i = 0; i < moves; i++)
    {
        vector<pair<int, int>> valid;

        for (auto d : dirs)
        {
            int nx = zx + d.first;
            int ny = zy + d.second;

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 &&
                !(d.first == -lastMove.first && d.second == -lastMove.second))
            {
                valid.push_back(d);
            }
        }

        auto chosen = valid[rand() % valid.size()];

        int nx = zx + chosen.first;
        int ny = zy + chosen.second;

        swap(grid[zx][zy], grid[nx][ny]);

        lastMove = chosen;
        zx = nx;
        zy = ny;
    }

    return grid;
}
pair<int, int> findTile(vector<vector<int>> &grid, int val)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == val)
                return {i, j};
    return {-1, -1};
}

pair<int, int> findZero(vector<vector<int>> &grid)
{
    return findTile(grid, 0);
}




// Ruchir

void clearScreen()
{

    system("clear");
}

void draw()
{
    clearScreen();

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // Draw Pacman
            if (i == pacY && j == pacX)
                cout << RESET << "C" << BLUE;

            // Draw Ghost
            else if (i == ghostY && j == ghostX)
                cout << RESET << "G" << BLUE;

            else if (maze[i][j] == '*')
                cout << RED_DOT << BLUE;
            else
                cout << maze[i][j];
        }

        cout << endl;
    }

    cout << endl;
    cout << "Score : " << score << endl;
    cout << "Level : " << level << endl;

    cout << "Controls : W A S D" << endl;
    cout << "Press X to Exit" << endl;
}

void input()
{
    char move;
    cin >> move;

    int newX = pacX;
    int newY = pacY;

    switch (move)
    {
    case 'w':
    case 'W':
        newY--;
        break;

    case 's':
    case 'S':
        newY++;
        break;

    case 'a':
    case 'A':
        newX--;
        break;

    case 'd':
    case 'D':
        newX++;
        break;

    case 'x':
    case 'X':
        gameOver = true;
        return;
    }

    // Move only if NOT wall
    if (maze[newY][newX] != '#')
    {
        pacX = newX;
        pacY = newY;
    }
}

void moveGhost()
{
    int newGhostX = ghostX;
    int newGhostY = ghostY;

    // Horizontal Movement
    if (ghostX < pacX)
        newGhostX++;

    else if (ghostX > pacX)
        newGhostX--;

    if (maze[ghostY][newGhostX] != '#')
        ghostX = newGhostX;

    // Vertical Movement
    if (ghostY < pacY)
        newGhostY++;

    else if (ghostY > pacY)
        newGhostY--;

    if (maze[newGhostY][ghostX] != '#')
        ghostY = newGhostY;
}

void nextLevelMessage()
{
    cout << endl;
    cout << "LEVEL " << level << " STARTED!" << endl;
    cout << "Press Enter to Continue...";

    cin.ignore();
    cin.get();
}

void logic()
{
    // Food Collection
    if (maze[pacY][pacX] == '*')
    {
        score += 10;

        maze[pacY][pacX] = ' ';

        // LEVEL 2
        if (score == 10)
        {
            level = 2;

            // New Food
            maze[1][20] = '*';

            // Reset Positions
            pacX = 4;
            pacY = 10;

            ghostX = 22;
            ghostY = 10;

            nextLevelMessage();
        }

        // LEVEL 3
        else if (score == 20)
        {
            level = 3;

            // New Food
            maze[7][5] = '*';

            // Reset Positions
            pacX = 4;
            pacY = 10;

            ghostX = 22;
            ghostY = 10;

            nextLevelMessage();
        }

        else if (score == 30)
        {
            clearScreen();

            cout << "=========================" << endl;
            cout << "     YOU WON THE GAME!   " << endl;
            cout << "=========================" << endl;

            cout << "Final Score : " << score << endl;
            cout << "Final Level : " << level << endl;

            gameOver = true;
        }
    }

    moveGhost();

    if (pacX == ghostX && pacY == ghostY)
    {
        gameOver = true;
    }
}

// Akshit

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

bool valid(char arr[], int index)
{
    if (index < 1 || index > 9)
        return false;

    if (arr[index - 1] == 'X' || arr[index - 1] == 'O')
        return false;

    return true;
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
                {
                    if (arr[num] == 'X')
                        cout << GREEN << arr[num++] << RED;
                    else if (arr[num] == 'O')
                    {
                        cout << BLUE << arr[num++] << RED;
                    }

                    else
                        cout << arr[num++];
                }

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
