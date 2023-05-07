


// Q9.Job sequencing with deadlines problem follow the following rules to obtain the feasible 
// solution: 
//  Each job takes one unit of time.
//  If job starts before or at its deadline, profit is obtained, otherwise no profit.
//  Goal is schedule jobs to maximize the total profit.
// Write a program using greedy method to solve this problem when no. of jobs n=7, profits 
// (𝑃1, 𝑃2, 𝑃3, … . , 𝑃7) = (3, 5, 20, 18, 1, 6, 30) and deadlines (𝑑1, 𝑑2, 𝑑3, … . , 𝑑7) =
// (1, 3, 4, 3, 2, 1, 2)



#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int job_sequencing_deadlines(vector<int>& profits, vector<int>& deadlines) {
    int n = profits.size();
    vector<int> jobs(n);
    for (int i = 0; i < n; i++) {
        jobs[i] = i;
    }
    sort(jobs.begin(), jobs.end(), [&](int a, int b) {
        return profits[a] > profits[b];
    });

    vector<int> schedule(*max_element(deadlines.begin(), deadlines.end()));
    int total_profit = 0;

    for (int i : jobs) {
        int d = deadlines[i] - 1;
        while (d >= 0 && schedule[d] != 0) {
            d--;
        }
        if (d >= 0) {
            schedule[d] = i + 1;
            total_profit += profits[i];
        }
    }

    return total_profit;
}

int main() {
    vector<int> profits = {3, 5, 20, 18, 1, 6, 30};
    vector<int> deadlines = {1, 3, 4, 3, 2, 1, 2};
    cout << job_sequencing_deadlines(profits, deadlines) << endl;
    return 0;
}
