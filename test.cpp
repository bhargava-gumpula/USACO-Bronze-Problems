// incomplete
#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n, m;
vector<int> nums;
vector<int> a;
vector<bool> picked;
unordered_set<string> used;

void com (int current) {
    if (current == n) {

        string temp = "";

        for (int i = 0; i < n; i++) {
            temp += to_string(nums[a[i]]);
        }

        sort(temp.begin(), temp.end());

        if (used.count(temp) == 0) {
            used.insert(temp);

            for (auto a : nums) {
                for (auto b : temp) {
                    if (a == b-'0') {
                        cout << b;
                    }
                }
            }

            cout << endl;
        }
    }

    else {
        for (int i = 0; i < m; i++) {
            if (! picked[i]) {
                a[current] = i;
                picked[i] = true;
                com(current+1);
                picked[i] = false;
            }
        }
    }
}


int main () {
    cin >> m;
    nums.resize(m);
    picked.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> nums[i];
        picked[i] = false;
    }

    cin >> n;
    a.resize(n);

    com(0);
}