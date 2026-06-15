#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main () {

    ifstream fin("crosswords.in");
    ofstream fout("crosswords.out");

    int n;
    int m;
    fin >> n >> m;


    vector<vector<char> > grid(0);

    for(int i = 0; i < n; i++) {
        string line;
        fin >> line;
        vector<char> chars(line.begin(), line.end());
        grid.push_back(chars);
    }

    vector<vector<int> > locations(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // work here
            bool add = false;
            if (j == 0 || grid[i][j-1] == '#') {
                if (j+2 <= m-1 && grid[i][j] == '.' && grid[i][j+1] == '.' && grid[i][j+2] == '.') {
                    add = true;
                }
            }
            if (i == 0 || grid[i-1][j] == '#') {
                if (i+2 <= n-1 && grid[i][j] == '.' && grid[i+1][j] == '.' && grid[i+2][j] == '.') {
                    add = true;
                }
            }
            if (add) {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                locations.push_back(temp);
            }
        }
    }

    fout << locations.size() << endl;
    for (int i = 0; i < locations.size(); i++) {
        fout << locations.at(i).at(0) + 1 << " " << locations.at(i).at(1) + 1 << endl;
    }

    fin.close();
    fout.close();
}