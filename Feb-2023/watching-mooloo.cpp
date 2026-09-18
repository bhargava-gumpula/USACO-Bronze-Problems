#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    long long n;
    long long k;

    cin >> n >> k;

    long long temp;
    cin >> temp;
    long long prev = temp;
    long long price = k+1;

    for (long long i = 1; i < n; i++) {
        long long current;
        cin >> current;

        if (current-prev > k+1) {
            price += k+1;
        }   
        else {
            price += current-prev;
        }

        prev = current;
    }
    cout << price << endl;
}