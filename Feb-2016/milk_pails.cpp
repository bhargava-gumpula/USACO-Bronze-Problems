#include <stdio.h>
#include <set>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    ifstream fin("pails.in");
    ofstream fout("pails.out");

    int x;
    int y;
    int m;

    fin >> x >> y >> m;

    int max_filled = 0;
    int temp = floor(m/x);

    for (int i = 0; i < temp; i++) {
        int x_count = (temp - i) * x;
        int y_count = floor((m - ((temp - i) * x)) / y) * y;
        int change = max(((temp - i) * x) + (i) * y, max_filled);
        if (change <= m)
            max_filled = change;
    }


    temp = floor(m / y);

    for (int i = 0; i < temp; i++) {
        int y_count = (temp - i) * y;
        int x_count = floor((m - ((temp - i) * y)) / x) * x;
        int change = max(y_count + x_count, max_filled);
        if (change <= m)
            max_filled = change;
    }

    fout << max_filled << endl;

    fin.close();
    fout.close();
}
