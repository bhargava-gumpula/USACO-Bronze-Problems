#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<pair<char, int>> cows(0);

    for (int i = 0; i < n; i++) {
        char sign;
        int margin;
        cin >> sign >> margin;
        pair<char, int> temp;
        temp = make_pair(sign, margin);
        cows.push_back(temp);
    }

    int min_liars = 1e9;
    for (int i = 0; i < n; i++) {
        int liars = 0; 
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }

            pair<char, int> cow1 = cows.at(i);
            pair<char, int> cow2 = cows.at(j);
            int bessie_loc = cow1.second;
            if (cow2.first == 'L' && bessie_loc > cow2.second) {
                liars++;
            }
            else if(cow2.first == 'G' && bessie_loc < cow2.second) {
                liars++;
            }
        }
        min_liars = min(min_liars, liars);
    }
    cout << min_liars << endl;
}