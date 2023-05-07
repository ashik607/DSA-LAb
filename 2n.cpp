
// bubbole sort
#include <bits/stdc++.h>
using namespace std;

void wow()
{
    int n, i, j, temp;

    cout << "enter number of elements in array: ";
    cin >> n;

    int num[n];
    cout << "enter elements of array: ";
    for (i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }

    cout << "sorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
}

int main()
{
    wow();
    return 0;
}
