#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");

    int n;
    fin >> n;

    vector<pair<int, int>> guards(n);

    for (int i = 0; i < n; i++) {
        int start;
        int end;
        fin >> start >> end;
        guards[i] = {start, end};
    }

    int max_dist = 0;
    for (int i = 0; i < n; i ++) {
        vector<bool> dist(1000);
        int dist2 = 0;
        for (int x = 0; x < 1000; x++) {
            dist.at(x) = false;
        }
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int start = guards.at(j).first;
            int end = guards.at(j).second;
            for (int x = start; x < end; x++) {
                dist.at(x) = true;
            }
        }
        for (int x = 0; x < 1000; x++) {
            if (dist.at(x) == true) {
                dist2 ++;
            }
        }

        max_dist = max(max_dist, dist2);
    }
    fout << max_dist << endl;

    fin.close();
    fout.close();
}