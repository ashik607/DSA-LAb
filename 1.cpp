


// #Problem-1: Write a Program to insert 
// and delete an element into a linear array

#include <iostream>
#include <array>

using namespace std;

// insert the element
void insertElements(array<int, 100> &arr, int &n) {
    int idx, ele;
    cout << "Enter the index number : ";
    cin >> idx;
    cout << "Enter the element : ";
    cin >> ele;
    if (idx >= n) {
        cout << "Invalid index." << endl;
        return;
    }
    for (int i = n - 1; i >= idx; i--) {
        arr[i+1] = arr[i];
    }
    arr[idx] = ele;
    n++;
    cout << "After insertion the array : " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// delete the element
void deleteElements(array<int, 100> &arr, int &n) {
    int pos;
    cout << "Enter the delete index number : ";
    cin >> pos;
    if (pos >= n) {
        cout << "Invalid index." << endl;
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    cout << "After the delete the element : " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

// main function
int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;
    array<int, 100> arr;
    cout << "Enter elements are : " << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    while (true) {
        int press;
        cout << "\nIf press 1 then go to insert option." << endl;
        cout << "If press 2 then go to delete option." << endl;
        cout << "If press 0 then go to exit." << endl;
        cin >> press;
        if (press == 1) {
            insertElements(arr, n);
        } else if (press == 2) {
            deleteElements(arr, n);
        } else {
            cout << "Exit" << endl;
            break;
        }
    }
    return 0;
}
