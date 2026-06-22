#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int main () {

    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    vector<int> road (100);
    vector<int> bessie (100);

    int n;
    int m;
    fin >> n >> m;


    int traveled = 0;
    for (int i = 0; i < n; i++) {
        int length;
        int speed;

        fin >> length >> speed;

        
        for (int j = 0; j < length; j++) {
             road.at(j + traveled) = speed;
        }
        traveled += length;
    }

    int traveled2 = 0;
    for (int i = 0; i < m; i++) {
        int length;
        int speed;
        
        fin >> length >> speed;

        for (int j = 0; j < length; j++) {
             bessie.at(j + traveled2) = speed;
        }
        traveled2 += length;
    }

    int max_difference = 0;
    for (int i = 0; i < 100; i++) {
        if (bessie.at(i) > road.at(i)) {
            max_difference = max(max_difference, bessie.at(i) - road.at(i));
        }
    }

    fout << max_difference << endl;



    fin.close();
    fout.close();
}