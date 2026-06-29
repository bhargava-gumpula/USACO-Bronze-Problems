#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main () {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int n;
    int k;
    vector<int> diamonds(0);


    fin >> n >> k;

    for (int i = 0; i < n; i++) {
        int temp;
        fin >> temp;
        diamonds.push_back(temp);
    }

    sort(diamonds.begin(), diamonds.end());
    vector<int> count_vec(0);
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = i; j < n; j++) {
            if (diamonds.at(i) + k >= diamonds.at(j)) {
                count++;
            }
            else {
                break;
            }
        }
        count_vec.push_back(count);
    }

    fout << *max_element(count_vec.begin(), count_vec.end()) << endl;

    fin.close();
    fout.close();
}