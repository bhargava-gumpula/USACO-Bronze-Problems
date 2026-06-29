#include <vector>
#include <unordered_set>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> flowers(0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        flowers.push_back(temp);
    }

    int main_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double count = 0;
            unordered_set<int> uniques;
            for (int k = i; k <= j; k++) {
                count += (double) flowers.at(k);
                uniques.insert(flowers.at(k));
            }
            count /= j-i+1;
            if (count == (int)count && uniques.count((int)count) == 1) {
                main_count ++;
            }
            

        }
    }
    cout << main_count << endl;
}