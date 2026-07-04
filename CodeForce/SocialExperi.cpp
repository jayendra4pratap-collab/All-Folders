#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n <= 3)
            cout << n;
        else
        {
            if (n % 2 == 0)
                cout << "0";
            else
                cout << "1";
        }
        cout << endl;

    }
}