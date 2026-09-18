#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main() {

    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");

    int n;
    fin >> n;

    vector<vector<char>> grid(n);
    for (int i = 0; i < n; i++) {
        string temp_row;
        fin >> temp_row;
        vector<char> row(n);
        for (int j = 0; j < n; j++) {
            row.at(j) = temp_row[j];
        }
        grid.at(i) = row;
    }

    int flips = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (grid[i][j] == '1') {
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++) {
                        if (grid[x][y] == '1') {
                            grid[x][y] = '0';
                        }
                        else {
                            grid[x][y] = '1';
                        }
                    }
                }
                flips++;
            }
        }
    }

    fout << flips << endl;

    fin.close();
    fout.close();

}