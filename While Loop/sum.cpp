#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;

    cout << "Enter numbers to sum (0 to finish): ";
    cin >> num;

    while (num != 0) {
        sum += num;
        cin >> num;
    }

    cout << "Total sum: " << sum << endl;
    return 0;
}

