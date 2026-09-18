// incomplete
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main () {
    int t;
    cin >> t;

    vector<pair<int, int>> ranges = {
                                    {45, 49},
                                    {445, 499},
                                    {4445, 4999},
                                    {44445, 49999},
                                    {444445, 499999},
                                    {4444445, 4999999},
                                    {44444445, 49999999},
                                    {444444445, 499999999}
                                };



    for (int i = 0; i < t; i++) {

        int n, count = 0;
        cin >> n;



        for (int j = 0; j < ranges.size(); j++) {
            if (n >= ranges[j].first && n <= ranges[j].second) {
                count += n-ranges[j].first + 1;
            }
            else if (n < ranges[j].first) {
                break;
            }
            else {
                count += ranges[j].second - ranges[j].first + 1;
            }
        }
        cout << count << endl;
    }
}
