#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    vector<long long> cows(n);
    for (int i = 0; i < n; i++) {
        long long pay;
        cin >> pay;

        cows.at(i) = pay;
    }
    sort(cows.begin(), cows.end());

    int count = 0;
    long long max_pay = 0;
    long long amount = 0;
    for (int i = 0; i < n; i++) {
        long long pay = cows.at(i) * (n-count);

        if (pay > max_pay) {
            max_pay = pay;
            amount = cows.at(i);
        }
        count ++;
    }
    cout << max_pay << ' ' << amount << endl;
}