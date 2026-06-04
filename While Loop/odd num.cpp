#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (i < 10) {
        i++;

        if (i % 2 == 0) {
            continue; 
        }

        cout << "Odd number: " << i << endl;
    }

    return 0;
}

