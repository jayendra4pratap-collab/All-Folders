#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int index;

    try {
        cout << "Enter index: ";
        cin >> index;

        if (index < 0 || index >= 5) {
            throw "Index out of range";
        }

        cout << "Element: " << arr[index] << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}