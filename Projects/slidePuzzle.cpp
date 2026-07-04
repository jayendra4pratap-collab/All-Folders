#include <iostream>
#include <cstdlib>
#include <ctime>
#include <termios.h>
#include <unistd.h>
using namespace std;

const int N = 3;
int board[N][N];
int emptyX, emptyY;

// -------- getch() for Mac/Linux --------
char getch()
{
    struct termios oldt, newt;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

// -------- Setup --------
void setup()
{
    int num = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = num++;

    board[N - 1][N - 1] = 0;
    emptyX = N - 1;
    emptyY = N - 1;

    srand(time(0));

    // shuffle
    for (int k = 0; k < 100; k++)
    {
        int dir = rand() % 4;
        int nx = emptyX, ny = emptyY;

        if (dir == 0)
            nx--;
        if (dir == 1)
            nx++;
        if (dir == 2)
            ny--;
        if (dir == 3)
            ny++;

        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            swap(board[emptyX][emptyY], board[nx][ny]);
            emptyX = nx;
            emptyY = ny;
        }
    }
}

// -------- Draw --------
void draw()
{
    system("clear");

    cout << "Sliding Puzzle (Use Arrow Keys)\n\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
                cout << "   ";
            else
                cout << " " << board[i][j] << " ";
        }
        cout << endl;
    }
}

// -------- Input (Arrow Keys) --------
void input()
{
    char ch = getch();

    if (ch == 27)
    {                 // ESC
        getch();      // skip '['
        ch = getch(); // actual key

        int nx = emptyX, ny = emptyY;

        switch (ch)
        {
        case 'A':
            nx--;
            break; // UP
        case 'B':
            nx++;
            break; // DOWN
        case 'C':
            ny++;
            break; // RIGHT
        case 'D':
            ny--;
            break; // LEFT
        }

        if (nx >= 0 && nx < N && ny >= 0 && ny < N)
        {
            swap(board[emptyX][emptyY], board[nx][ny]);
            emptyX = nx;
            emptyY = ny;
        }
    }
}

// -------- Check Win --------
bool isSolved()
{
    int num = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == N - 1 && j == N - 1)
            {
                if (board[i][j] != 0)
                    return false;
            }
            else
            {
                if (board[i][j] != num++)
                    return false;
            }
        }
    }
    return true;
}

// -------- Main --------
int main()
{
    setup();

    while (true)
    {
        draw();

        if (isSolved())
        {
            cout << "\n🎉 Puzzle Solved!\n";
            break;
        }

        input();
    }

    return 0;
}