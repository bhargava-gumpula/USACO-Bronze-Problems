// incomplete
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    int m = min(n, 30); // deals beyond level 30 can never matter since x <= 1e9 < 2^30
    vector<long long> a(m);
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        if (i < m) a[i] = temp;
    }

    vector<long long> effective_cost(m);
    effective_cost[0] = a[0];
    for (int i = 1; i < m; i++) {
        effective_cost[i] = min(a[i], 2 * effective_cost[i-1]);
    }

    for (int i = 0; i < q; i++) {
        long long wanted;
        cin >> wanted;

        long long remaining = wanted;
        long long running_total = 0;
        long long best = -1;

        for (int j = m - 1; j >= 0; j--) {
            long long buckets = 1LL << j;      // deal j+1 gives 2^j buckets
            long long cost = effective_cost[j];

            // candidate: round UP at this level to finish right now (may overshoot)
            long long take_ceil = (remaining + buckets - 1) / buckets;
            long long candidate = running_total + take_ceil * cost;
            if (best == -1 || candidate < best) best = candidate;

            // continue descending: take the floor amount at this level
            long long take_floor = remaining / buckets;
            running_total += take_floor * cost;
            remaining -= take_floor * buckets;
        }

        cout << best << endl;
    }
}