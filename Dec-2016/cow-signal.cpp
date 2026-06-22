#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");


    int m;
    int n;
    int k;

    fin >> m >> n >> k;

    for (int i = 0; i < m; i++) {
        string line;
        fin >> line;
        for (int j = 0; j < k; j++) {
            for (int a = 0; a < n; a ++) {
                for (int b = 0; b < k; b++) {
                    fout << (char) line[a];
                }
            }
            fout << endl;
        }
    }
    fout.close();
    fin.close();
}