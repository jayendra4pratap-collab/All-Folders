#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <conio.h> 
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

const int width = 10;
const int height = 10;

int pacX, pacY;
int foodX, foodY;
int score = 0;
char moveDir;

void setup() {
    pacX = width / 2;
    pacY = height / 2;

    srand(time(0));
    foodX = rand() % width;
    foodY = rand() % height;
}

void draw() {
    system("clear");

    for (int i = 0; i <2*width + 4; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < 2*width + 4; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        cout << "##";
        for (int j = 0; j < width; j++) {
            if (i == pacY && j == pacX)
                cout << "🐍";  
            else if (i == foodY && j == foodX)
                cout << "🍗";  
            else
                cout << "  ";
        }
        cout << "##" << endl;
    }

    for (int i = 0; i < 2*width + 4; i++)
        cout << "#";
        cout<<endl;

    for (int i = 0; i < 2*width + 4; i++)
        cout << "#";

    cout << "\nScore: " << score << endl;
    cout << "Move (W/A/S/D): ";
}

char getch() {
    struct termios oldt, newt;
    char ch;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    
    newt.c_lflag &= ~(ICANON | ECHO); // disable buffering
    
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return ch;
}

void input() {
    char ch = getch();

    if (ch == 27) { // ESC sequence
        getch();    // skip '['
        ch = getch();

        switch (ch) {
            case 'A': moveDir = 'w'; break; // UP
            case 'B': moveDir = 's'; break; // DOWN
            case 'C': moveDir = 'd'; break; // RIGHT
            case 'D': moveDir = 'a'; break; // LEFT
        }
    }
}
/*void input() {
    char ch = _getch();

    if (ch == 0 || ch == -32) {
        ch = _getch();

        switch (ch) {
            case 72: moveDir = 'w'; break; // UP
            case 80: moveDir = 's'; break; // DOWN
            case 75: moveDir = 'a'; break; // LEFT
            case 77: moveDir = 'd'; break; // RIGHT
        }
    }
}*/

// Logic
void logic() {
    switch (moveDir) {
        case 'a': pacX--; break;
        case 'd': pacX++; break;
        case 'w': pacY--; break;
        case 's': pacY++; break;
    }

    // Boundary check
    if (pacX < 0) pacX = 0;
    if (pacX >= width) pacX = width - 1;
    if (pacY < 0) pacY = 0;
    if (pacY >= height) pacY = height - 1;

    // Eating food
    if (pacX == foodX && pacY == foodY) {
        score += 10;
        foodX = rand() % width;
        foodY = rand() % height;
    }
}

int main() {
    setup();

    while (true) {
        draw();
        input();
        logic();
    }

    return 0;
}