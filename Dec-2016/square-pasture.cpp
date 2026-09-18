#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


int main() {

    ifstream fin("square.in");
    ofstream fout("square.out");
    
    pair<pair<int, int>, pair<int, int>> rec1;
    pair<pair<int, int>, pair<int, int>> rec2;

    int x1, y1, x2, y2;
    fin >> x1 >> y1 >> x2 >> y2;

    rec1.first.first = x2;
    rec1.first.second = y2;
    rec1.second.first = x1;
    rec1.second.second = y1;

    fin >> x1 >> y1 >> x2 >> y2;

    rec2.first.first = x2;
    rec2.first.second = y2;
    rec2.second.first = x1;
    rec2.second.second = y1;


    // we have rec1 and rec2 which are pairs of top and bottom corners.

    int x_max = max(max(rec1.first.first, rec1.second.first), max(rec2.first.first, rec2.second.first));
    int y_max = max(max(rec1.first.second, rec1.second.second), max(rec2.first.second, rec2.second.second));
    int x_min = min(min(rec1.first.first, rec1.second.first), min(rec2.first.first, rec2.second.first));
    int y_min = min(min(rec1.first.second, rec1.second.second), min(rec2.first.second, rec2.second.second));

    int bam = max((x_max - x_min), (y_max - y_min));
    fout << bam * bam << endl;

    fin.close();
    fout.close();
}