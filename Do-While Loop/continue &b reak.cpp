#include <iostream>
using namespace std;

int main() {
    int i = 0;

    do {
        i++;
        if (i == 3) continue; // skips the rest when i is 3
        if (i == 6) break;    // exits loop when i is 6
        cout << "i = " << i << endl;
    } while (i < 10);

    return 0;
}

