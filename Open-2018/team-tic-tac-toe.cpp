#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main () {

    ifstream fin ("tttt.in");
    ofstream fout ("tttt.out");

    unordered_set<string> score_one;
    unordered_set<string> score_two;

    vector<vector<int>> grid(0);


    for (int i = 0; i < 3; i++) {
        string line;
        fin >> line;

        vector<int> temp(0);

        for (auto a: line) {
            temp.push_back(a);
        }

        grid.push_back(temp);
    }

    for (int i = 0; i < 3; i++) {
        unordered_set<int> temp_set;
        unordered_set<int> temp_set2;
        for (int j = 0; j < 3; j++) {
            temp_set.insert(grid.at(i).at(j));
            temp_set2.insert(grid.at(j).at(i));
        }

        string temp_str(temp_set.begin(), temp_set.end());
        string temp_str2(temp_set2.begin(), temp_set2.end());
        sort(temp_str.begin(), temp_str.end());
        sort(temp_str2.begin(), temp_str2.end());

        if (size(temp_set) == 2) {
            score_two.insert(temp_str); 
        }
        else if (size(temp_set) == 1) {
            score_one.insert(temp_str);
        }
        if (size(temp_set2) == 2) {
            score_two.insert(temp_str2);
        }
        else if (size(temp_set2) == 1) {
            score_one.insert(temp_str2);
        }
    }

    unordered_set<int> diagonal_set;
    diagonal_set.insert(grid[0][0]);
    diagonal_set.insert(grid[1][1]); 
    diagonal_set.insert(grid[2][2]);

    string diagonal_str(diagonal_set.begin(), diagonal_set.end());
    sort(diagonal_str.begin(), diagonal_str.end());
    
    if (size(diagonal_set) == 2) {
            score_two.insert(diagonal_str);
        }
    else if (size(diagonal_set) == 1) {
        score_one.insert(diagonal_str);
    }

    unordered_set<int> diagonal_set2;
    diagonal_set2.insert(grid[2][0]);
    diagonal_set2.insert(grid[1][1]); 
    diagonal_set2.insert(grid[0][2]);

    string diagonal_str2(diagonal_set2.begin(), diagonal_set2.end());
    sort(diagonal_str2.begin(), diagonal_str2.end());
    
    if (size(diagonal_set2) == 2) {
            score_two.insert(diagonal_str2);
        }
    else if (size(diagonal_set2) == 1) {
        score_one.insert(diagonal_str2);
    }

    fout << score_one.size() << endl;
    fout << score_two.size() << endl;

    fin.close();
    fout.close();
}