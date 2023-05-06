

// #Problem-10: Write a program using greedy method to solve this problem when no of job 𝑛 = 5, profits (𝑃1, 𝑃2, 𝑃3, 𝑃4, 𝑃5)=(3,25,1,6,30) and deadlines (𝑑1,𝑑2, 𝑑3, 𝑑4, 𝑑5)=(1,3,2,1,2).
// def printJobScheduling(arr, t):
//     # length of array


#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

// structure for job
struct Job {
    char id;
    int deadline, profit;
};

// Function to sort jobs by profit
bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to find the maximum profit sequence of jobs
void printJobScheduling(Job arr[], int n, int t) {
    // Sort jobs by profit
    sort(arr, arr + n, compare);

    // To keep track of free time slots
    bool result[t];
    memset(result, false, sizeof(result));

    // To store result (Sequence of jobs)
    char job[t];
    memset(job, '-', sizeof(job));

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job
        // (Note that we start from the
        // last possible slot)
        for (int j = min(t - 1, arr[i].deadline - 1); j >= 0; j--) {
            // Free slot found
            if (result[j] == false) {
                result[j] = true;
                job[j] = arr[i].id;
                break;
            }
        }
    }

    // Print the sequence
    cout << "Following is the maximum profit sequence of jobs:" << endl;
    for (int i = 0; i < t; i++) {
        cout << job[i] << " ";
    }
}

// Main Function
int main() {
    int n = 5, t = 3;
    Job arr[n] = { {'a', 1, 3}, {'b', 3, 25}, {'c', 2, 1}, {'d', 1, 6}, {'e', 2, 30} };
    printJobScheduling(arr, n, t);
    return 0;
}
