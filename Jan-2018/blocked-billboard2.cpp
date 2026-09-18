// incomplete
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int main() {

    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    
    vector<vector<bool>> grid(2000);
    for (int i = 0; i < 2000; i++) {
        vector<bool> row (2000);
        for (int j = 0; j < 2000; j++){
            row[j] = false;
        }
        grid[i] = row;
    }

    int x1; 
    int x2; 
    int y1;
    int y2;

    fin >> x1 >> y1 >> x2 >> y2;
    x1+=1000;
    x2+=1000;
    y1+=1000;
    y2+=1000;

    for (int x = x1; x < x2; x++) {
        for (int y = y1; y < y2; y++) {
            grid[x][y] = true;
        }
    }

    fin >> x1 >> y1 >> x2 >> y2;
    x1+=1000;
    x2+=1000;
    y1+=1000;
    y2+=1000;

    for (int x = x1; x < x2; x++) {
        for (int y = y1; y < y2; y++) {
            grid[x][y] = false;
        }
    }


    pair<int, int> tcorner = {2001, 0};
    pair<int, int> bcorner = {0, 2001};

    for (int x = 0; x < 2000; x++) {
        for (int y = 0; y < 2000; y++) {
            if (grid[x][y] == true) {
                tcorner.first = min(tcorner.first, x);
                tcorner.second = max(tcorner.second, y);
                bcorner.first = max(bcorner.first, x);
                bcorner.second = min(bcorner.second, y); 
            }
        }
    }

    if (tcorner.first == 2001 && tcorner.second == 0 && bcorner.first == 0 && bcorner.second == 2001) {
        fout << 0 << endl;
    }
    else {
        fout << (bcorner.first - tcorner.first + 1) * (tcorner.second - bcorner.second + 1) << endl;
    }
    fin.close();
    fout.close();
}