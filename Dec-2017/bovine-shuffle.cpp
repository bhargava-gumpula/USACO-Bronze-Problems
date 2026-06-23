#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> shuffle (vector<int> num_order, vector<int> num_shuffle) {
    vector<int> new_order(0);

    for (auto a : num_shuffle) {
        new_order.push_back(num_order.at(a-1));
    }

    return new_order;
}


int main() {

    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int n;
    fin >> n;
    
    vector<int> shuffle_pattern(0);
    vector<int> ids(0);
    vector<int> initial(0);

    for (int i = 0; i < n; i++) {
        int temp;
        fin >> temp;

        shuffle_pattern.push_back(temp);
        initial.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        int temp;
        fin >> temp;

        ids.push_back(temp);
    }

    
    initial = shuffle(initial, shuffle_pattern);
    initial = shuffle(initial, shuffle_pattern);
    initial = shuffle(initial, shuffle_pattern);

    for (auto a: initial) {
        fout << ids.at(a) << endl;
    }
    fin.close();
    fout.close();
}