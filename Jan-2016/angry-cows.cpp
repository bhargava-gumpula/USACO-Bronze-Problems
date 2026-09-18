#include <vector>
#include <set>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

int main () {

    ifstream fin ("angry.in");
    ofstream fout("angry.out");

    int n;
    fin >> n;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++) {
        int cow;
        fin >> cow;
        
        cows.at(i) = {cow, 0};   // cow is the position and 0 is t value
    }

    sort(cows.begin(), cows.end());

    int max_count = 0;
    for (int i = 0; i < n; i++) {   // starting position of cows
        // simulate explosions    (reset cows every time)
        for (int j = 0; j < n; j++) {
            cows.at(j).second = 0;
        }
        cows.at(i).second = 1;
        bool changed = true;
        while (changed) {
            changed = false;
            for (int j = 0; j < n; j++) {  // checking what cows have already exploded
                if (cows.at(j).second > 0) {  // if exploded...



                    int t = cows.at(j).second;
                    int pos  = cows.at(j).first;

                    // expolde neighboring cows
                    for (int y = 0; y < n; y++) {
                        if (cows.at(y).second > 0) {
                            continue;
                        }
                        if (cows.at(y).first <= pos+t && cows.at(y).first >= pos-t) {
                            cows.at(y).second = t+1;
                            changed = true;
                        }
                    }
                }
            }
        }
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (cows.at(j).second > 0) {
                count++;
            }
        }


        max_count = max(max_count, count);
    }
    fout << max_count << endl;

    fin.close();
    fout.close();
}