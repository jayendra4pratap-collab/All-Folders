#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int HEIGHT = 12;
const int WIDTH = 28;

char maze[HEIGHT][WIDTH + 1] =
{
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
    "###########################"
};


int pacX = 4, pacY = 10;
int ghostX = 22, ghostY = 10;

int score = 0;
int level = 1;

bool gameOver = false;

void clearScreen()
{
    cout << string(50, '\n');
}

void draw()
{
    clearScreen();

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            // Draw Pacman
            if(i == pacY && j == pacX)
                cout << "C";

            // Draw Ghost
            else if(i == ghostY && j == ghostX)
                cout << "G";

            // Draw Maze
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

    switch(move)
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
    if(maze[newY][newX] != '#')
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
    if(ghostX < pacX)
        newGhostX++;

    else if(ghostX > pacX)
        newGhostX--;

    if(maze[ghostY][newGhostX] != '#')
        ghostX = newGhostX;

    // Vertical Movement
    if(ghostY < pacY)
        newGhostY++;

    else if(ghostY > pacY)
        newGhostY--;

    if(maze[newGhostY][ghostX] != '#')
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
    if(maze[pacY][pacX] == '*')
    {
        score += 10;

        // Remove collected food
        maze[pacY][pacX] = ' ';

        // LEVEL 2
        if(score == 10)
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
        else if(score == 20)
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

        // WIN CONDITION
        else if(score == 30)
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

    // Move Ghost
    moveGhost();

    // Ghost catches Pacman
    if(pacX == ghostX && pacY == ghostY)
    {
        gameOver = true;
    }
}

int main()
{
    srand(time(0));

    while(!gameOver)
    {
        draw();
        input();
        logic();
    }

    // If player loses
    if(score < 30)
    {
        clearScreen();

        cout << "======================" << endl;
        cout << "      GAME OVER       " << endl;
        cout << "======================" << endl;

        cout << "Final Score : " << score << endl;
        cout << "Final Level : " << level << endl;
    }

    return 0;
}