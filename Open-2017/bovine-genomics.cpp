#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");

    int n;
    int m;

    fin >> n >> m;

    vector<vector<char>> spotty_cows(n);
    vector<vector<char>> plain_cows(n);


    for (int i = 0; i < n; i++) {
        vector<char> cows(m);
        for (int j = 0; j < m; j++) {
            char base;
            fin >> base;
            cows.at(j) = base;            
        }
        spotty_cows.at(i) = cows;
    }

    for (int i = 0; i < n; i++) {
        vector<char> cows(m);
        for (int j = 0; j < m; j++) {
            char base;
            fin >> base;
            cows.at(j) = base;            
        }
        plain_cows.at(i) = cows;
    }


    // we have spotty cows and plain cows as vector<vector<char>>

    int locations = 0;
    for (int i = 0; i < m; i++) {

        unordered_set<char> spotty;
        unordered_set<char> plain;

        for (int j = 0; j < n; j++) {
            spotty.insert(spotty_cows.at(j).at(i));
        }
        for (int j = 0; j < n; j++) {
            plain.insert(plain_cows.at(j).at(i));
        }

        bool match = false;
        for (auto spot : spotty) {
            for (auto p : plain) {
                if (spot == p) {
                    match = true;
                }
            }
        }

        if (not match) {
            locations ++;
        }



    }
    fout << locations << endl;

    fin.close();
    fout.close();
}