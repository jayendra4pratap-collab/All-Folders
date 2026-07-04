#include <iostream>
using namespace std;

class IntegerArray {
private:
    int* arr;      // dynamically allocated array
    int n;         // number of elements

public:
    // Constructor: allocate memory dynamically
    IntegerArray(int size) {
        n = size;
        arr = new int[n];
    }

    // Accept elements with validation
    void readElements() {
        for (int i = 0; i < n; i++) {
            int value;
            do {
                cout << "Enter element " << i << " (-1000 to 1000): ";
                cin >> value;
                if (value < -1000 || value > 1000)
                    cout << "Invalid input! Try again.\n";
            } while (value < -1000 || value > 1000);

            arr[i] = value;
        }
    }

    // Display all integers
    void display() const {
        cout << "Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Return maximum value
    int getMax() const {
        int maxVal = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }
        return maxVal;
    }

    // Return minimum value
    int getMin() const {
        int minVal = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < minVal)
                minVal = arr[i];
        }
        return minVal;
    }

    // Return sum of elements
    int getSum() const {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        return sum;
    }

    // Update element by index
    void updateElement(int index, int value) {
        if (index < 0 || index >= n) {
            cout << "Invalid index!\n";
            return;
        }
        if (value < -1000 || value > 1000) {
            cout << "Value out of allowed range!\n";
            return;
        }
        arr[index] = value;
        cout << "Element updated successfully\n";
    }

    // Destructor: free memory
    ~IntegerArray() {
        delete[] arr;
        cout << "Memory freed\n";
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Dynamically create object
    IntegerArray* obj = new IntegerArray(n);
    obj->readElements();

    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Display all integers\n";
        cout << "2. Update an integer\n";
        cout << "3. Show statistics\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj->display();
            break;

        case 2: {
            int index, value;
            cout << "Enter index to update: ";
            cin >> index;
            cout << "Enter new value (-1000 to 1000): ";
            cin >> value;
            obj->updateElement(index, value);
            break;
        }

        case 3:
            cout << "Maximum: " << obj->getMax() << endl;
            cout << "Minimum: " << obj->getMin() << endl;
            cout << "Sum: " << obj->getSum() << endl;
            break;

        case 4:
            delete obj;   // destructor called
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}