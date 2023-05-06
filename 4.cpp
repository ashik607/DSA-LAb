
// #Problem-4: Write a program to find an
//  element using the binary search algorithm


#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int lo=0, hi=n-1;
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            hi = mid-1;
        else
            lo = mid+1;
    }
    return -1;
}

int main() {
    int n, r;
    cout<<"Enter the number: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Enter the search number: ";
    cin>>r;
    int result = binarySearch(arr, n, r);
    if(result == -1)
        cout<<"Element not present in array.\n";
    else
        cout<<"Element present at index "<<result<<endl;
    return 0;
}
