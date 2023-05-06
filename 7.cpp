

// #Problem-7: Write a program to find a given pattern from text using the first pattern matching algorithm
// ###### KMP Algorithm ##########

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void computeLPSarray(string pat, int M, vector<int>& lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void PatternSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();
    vector<int> lps(M, 0);
    computeLPSarray(pat, M, lps);
    int i = 0;
    int j = 0;
    int cnt = 0;
    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        else {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
        if (j == M) {
            cout << "Pattern found at position " << i - j << endl;
            j = lps[j - 1];
            cnt++;
        }
    }
    if (cnt > 0) {
        cout << "Total pattern match : " << cnt << endl;
    }
    else {
        cout << "Pattern Not found" << endl;
    }
}

int main() {
    while (true) {
        cout << "\nPress 1 then go to pattern matching field." << endl;
        cout << "Press 0 then exit." << endl;
        int press;
        cin >> press;
        if (press == 1) {
            string txt, pat;
            cout << "Enter the pattern field : ";
            cin >> txt;
            cout << "Enter the pattern : ";
            cin >> pat;
            PatternSearch(pat, txt);
        }
        else {
            cout << "Exit" << endl;
            break;
        }
    }
    return 0;
}
