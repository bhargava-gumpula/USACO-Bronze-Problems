#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int main() {
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");

    int n;
    fin >> n;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        int temp;
        fin >> temp;

        cows.at(i) = temp;
    }

    vector<int> sorted_cows = cows;
    sort(sorted_cows.begin(), sorted_cows.end());

    int start = 1e9;
    int end = 0;
    for (int i = 0; i < n; i++) {
        int c = cows.at(i);
        int s = sorted_cows.at(i);

        if (c != s) {
            start = min(start, i);
            end = max(end, i);
        }
    }

    unordered_set<int> switches;
    for (int i = start; i < end; i++) {
        switches.insert(cows.at(i));
    }

    fout << switches.size() << endl;


    fin.close();
    fout.close();
}