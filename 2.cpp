

// #Problem-2: Write a program
//  to sort a linear array using the bubble sort algorithm


#include <iostream>
#include <array>

using namespace std;

void bubbleSort(array<int, 100> &arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int n;
    array<int, 100> arr;
    
    cout << "Enter the number : ";
    cin >> n;

    cout << "Enter the array elements : " << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }

    bubbleSort(arr, n);

    cout << "After Bubble sorting : " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
