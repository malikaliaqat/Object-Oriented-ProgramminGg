#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;

    do {
        cout << "Enter a number to add (0 to finish): ";
        cin >> num;
        sum += num;
    } while (num != 0);

    cout << "Total sum = " << sum << endl;
    return 0;
}

