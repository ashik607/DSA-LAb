

#include <iostream>
using namespace std;

int main() {
    int n, x;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> x;

    int index = -1; // initialize the index to -1
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            index = i; // update the index if the element is found
            break;
        }
    }

    if (index == -1) {
        cout << "Element not found in the array";
    }
    else {
        cout << "Element found at index " << index;
    }

    return 0;
}
