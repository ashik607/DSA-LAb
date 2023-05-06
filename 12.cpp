

// #Problem-12: Write a program to solve
// # the Tower of Hanoi problem for the 𝑁 disk



#include <iostream>
using namespace std;

void towerHanoi(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "Move disc " << n << " from " << A << " to " << B << endl;
    } else {
        towerHanoi(n - 1, A, C, B);
        cout << "Move disc " << n << " from " << A << " to " << B << endl;
        towerHanoi(n - 1, C, B, A);
    }
}

int main() {
    while (true) {
        cout << "Press 1 then go to work." << endl;
        cout << "Press 0 then exit." << endl;
        int n;
        cin >> n;
        if (n == 0) {
            cout << "Exit." << endl;
            break;
        } else {
            int number;
            cout << "How many discs : ";
            cin >> number;
            char a = 'A', b = 'B', c = 'C';
            cout << a << " " << b << " " << c << endl;
            towerHanoi(number, a, b, c);
        }
    }
    return 0;
}
