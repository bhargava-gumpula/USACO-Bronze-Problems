// incomplete
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main () {
    ifstream fin("herding.in");
    ofstream fout("herding.out");

    int b;
    int e;
    int m;
    
    fin >> b >> e >> m;
    vector<int> temp = {b, e, m};

    sort(temp.begin(), temp.end());

    b = temp[0];
    e = temp[1];
    m = temp[2];

    int max_steps = 0;
    int min_steps = 2; // the most steps it could possibly take is two.

    bool complete = false;
    // checks if cows are already in order
    if (e == b+1 && m == b+2) {
        min_steps = 0;
        max_steps = 0;
        complete = true;
    }

    // checking if one move is possible
    else if (e == b+2 || m == e+2) {
        min_steps = 1;
    }

    if (!complete) {
        max_steps = max(e-b, m-e) - 1;
    }
    
    fout << min_steps << endl << max_steps << endl;

    fin.close();
    fout.close();
}