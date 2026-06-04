#include <iostream>
using namespace std;

int main() {
    int number;

    do {
        cout << "Enter a number (0 to quit): ";
        cin >> number;
        cout << "You entered: " << number << endl;
    } while (number != 0);

    cout << "Loop exited." << endl;
    return 0;
}

