



// #Problem-3: Write a program to 
// find an element using a linear search algorithm.

#include <iostream>
#include <array>
using namespace std;

int linearSearch(int n, int x, array<int, 100> arr) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    array<int, 100> arr = {0};
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        arr[i] = m;
    }
    while (true) {
        cout << "If press 1 then go to search." << endl;
        cout << "If press 0 then exit." << endl;
        int press;
        cin >> press;
        if (press == 1) {
            int x;
            cout << "Enter the element number: ";
            cin >> x;
            int ans = linearSearch(n, x, arr);
            if (ans == -1) {
                cout << x << " are not present in this array" << endl;
            } else {
                cout << x << " are present in this " << ans << " number index array" << endl;
            }
        } else {
            cout << "Exit" << endl;
            break;
        }
    }
    return 0;
}
