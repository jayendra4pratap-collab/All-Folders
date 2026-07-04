#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

void printGrid(vector<vector<int>> &grid) {
    cout << "\n";
    for (auto &row : grid) {
        for (auto &val : row) {
            if (val == 0) cout << "  ";
            else cout << val << " ";
        }
        cout << endl;
    }
    cout << "\n";
}

bool isSolved(vector<vector<int>> &grid) {
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 2 && j == 2 && grid[i][j] == 0)
                return true;
            if (grid[i][j] != count++)
                return false;
        }
    }
    return true;
}

bool isSolvable(vector<int> &arr) {
    int inv = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (arr[i] && arr[j] && arr[i] > arr[j])
                inv++;
        }
    }
    return (inv % 2 == 0);
}

vector<vector<int>> generateHardGrid() {
    vector<int> arr = {0,1,2,3,4,5,6,7,8};

    do {
        random_shuffle(arr.begin(), arr.end());
    } while (!isSolvable(arr));

    vector<vector<int>> grid(3, vector<int>(3));
    int k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = arr[k++];

    return grid;
}

vector<vector<int>> generateMediumGrid() {
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},
        {7,8,0}
    };

    int zx = 2, zy = 2;

    int moves = 5 + rand() % 2;
    vector<pair<int,int>> dirs = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };

    pair<int,int> lastMove = {0,0};

    for (int i = 0; i < moves; i++) {
        vector<pair<int,int>> valid;

        for (auto d : dirs) {
            int nx = zx + d.first;
            int ny = zy + d.second;

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 &&
                !(d.first == -lastMove.first && d.second == -lastMove.second)) {
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
pair<int,int> findTile(vector<vector<int>> &grid, int val) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == val)
                return {i, j};
    return {-1, -1};
}

pair<int,int> findZero(vector<vector<int>> &grid) {
    return findTile(grid, 0);
}

int main() {
    srand(time(0));

    int level;
    cout << "Select Level:\n1. Medium\n2. Hard\nChoice: ";
    cin >> level;

    vector<vector<int>> grid;

    if (level == 1) grid = generateMediumGrid();
    else grid = generateHardGrid();

    cout << "\nCommands:\n";
    cout << "Enter: number + direction (W/A/S/D)\n";
    cout << "R = Reset, Q = Quit\n";

    while (true) {
        printGrid(grid);

        if (isSolved(grid)) {
            cout << "Huraahhh... Puzzle Solved!\n";
            break;
        }

        cout << "Enter move: ";
        string input;
        cin >> input;

        if (input == "Q" || input == "q") break;

        if (input == "R" || input == "r") {
            if (level == 1) grid = generateMediumGrid();
            else grid = generateHardGrid();
            continue;
        }

        if (input.length() < 2) {
            cout << "Invalid input!\n";
            continue;
        }

        int num = input[0] - '0';
        char dir = input[1];

        if (num < 1 || num > 8) {
            cout << "Invalid tile!\n";
            continue;
        }

        auto [x, y] = findTile(grid, num);

        int nx = x, ny = y;

        if (dir == 'W' || dir == 'w') nx--;
        else if (dir == 'S' || dir == 's') nx++;
        else if (dir == 'A' || dir == 'a') ny--;
        else if (dir == 'D' || dir == 'd') ny++;
        else {
            cout << "Invalid direction!\n";
            continue;
        }

        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3 && grid[nx][ny] == 0) {
            swap(grid[x][y], grid[nx][ny]);
        } else {
            cout << "Invalid move!\n";
        }
    }

    return 0;
}