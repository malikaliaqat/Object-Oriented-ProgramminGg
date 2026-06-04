#include <iostream>
using namespace std;

int main() {
    int i = 1;

    while (i <= 3) {
        int j = 1;
        while (j <= 2) {
            cout << "i = " << i << ", j = " << j << endl;
            j++;
        }
        i++;
    }

    return 0;
}

