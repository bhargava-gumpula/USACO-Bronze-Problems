#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>

using namespace std;

int main () {
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    int k;
    int n;

    fin >> k >> n;

    vector<vector<int>> sessions(0);
    for (int i = 0; i < k; i++) {
        vector<int> row(0);
        for (int j = 0; j < n; j++) { 
            int temp;
            fin >> temp;
            row.push_back(temp);
        }
        sessions.push_back(row);
    }
    int count = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = i+1; j < n; j++) {
            int cow1 = sessions[0][i];
            int cow2 = sessions[0][j];

            bool passed = true;
            for (int a = 1; a < k; a++) {
                int index1;
                int index2;
                for (int b = 0; b < n; b++) {
                    if (sessions[a][b] == cow1) {
                        index1 = b;
                    }
                    else if (sessions[a][b] == cow2) {
                        index2 = b;
                    }
                }
                if (index2 < index1) {
                    passed = false;
                    break;
                }
            }

            if (passed) {
                count ++;
            }
        }
    }
    fout << count << endl;

    fin.close();
    fout.close();
}