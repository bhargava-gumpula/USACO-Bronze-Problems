// incomplete
#include <stdio.h>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> ints(n);
    unordered_set<int> uniques;
    int temp1;
    int temp2;
    cin >> temp1 >> temp2;

    ints.at(0) = temp1;
    ints.at(1) = temp2;

    for (int i = 2; i < n; i++) {
        int temp;
        cin >> temp;

        ints.at(i) = temp;
    }
    for (int i = 0; i < n-2; i++) {
        if (ints[i] != ints[i+1] && ints[i+1] == ints[i+2]) {
            uniques.insert(ints[i] * 100 + ints[i+1] * 10 + ints[i]);
        }
    }

    cout << uniques.size() << endl;
}