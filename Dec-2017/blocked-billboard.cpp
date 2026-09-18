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

    for (int i = 0; i < 2; i++) {
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
            grid[x][y] = false;
        }
    }

    int count = 0; 
    for (int x = 0; x < 2000; x++) {
        for (int y = 0; y < 2000; y++) {
            if (grid[x][y] == true) {
                count ++;
            }
        }
    }

    fout << count << endl;

    fin.close();
    fout.close();
}