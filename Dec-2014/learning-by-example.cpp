#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main(void) {
    int n;
    int a;
    int b;

    cin >> n >> a >> b;

    map<int, string> cows;
    vector<int> weights(0);

    for (int i = 0; i < n; i++) {
        string temp1;
        int temp2;
        cin >> temp1 >> temp2;

        cows.insert({temp2, temp1});
        weights.push_back(temp2);
    }

    sort(weights.begin(), weights.end());

    int prev_weight = weights.at(0);
    string prev_spot = cows[prev_weight];
    int remove_count = 0;

    for (auto cow : weights) {
        if (cows[cow] == "NS") {
            if (prev_spot == "NS") {
                remove_count += round(abs(cow - prev_weight)) - 1;
            } 
            else if (prev_spot == "S") {
                remove_count += round(abs(cow - prev_weight) / 2);
            }
        }
        else if (cows[cow] == "S" && prev_spot == "NS") {
            remove_count += round(abs(cow - prev_weight) / 2);
        }
        prev_weight = cow;
        prev_spot = cows[prev_weight];
    }
    cout << (b-a + 1) - remove_count << endl;
}

