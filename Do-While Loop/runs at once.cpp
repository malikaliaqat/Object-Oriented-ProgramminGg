#include <iostream>
using namespace std;

int main() {
    int x = 10;

    do {
        cout << "This will run even if the condition is false." << endl;
    } while (x < 5); // false condition

    return 0;
}

