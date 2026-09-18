#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main () {
    ifstream fin("paint.in");
    ofstream fout("paint.out");

    int a;
    int b;
    int c;
    int d;

    fin >> a >> b >> c >> d;

    int covered = 0;

    // completely out of bounds
    if (d < a || b < c) {
        covered = (b-a) + (d-c);
    }

    // completely in bounds

    else if (c < a && d > b) {
        covered = d-c;
    }

    else if (a < c && b > d) {
        covered = b-a;
    }

    // partially in bounds

    else if (c < a && d < b) {
        covered = b - c;
    }

    else if (a < c && b < d) {
        covered = d-a;
    }

    // if they share an endpoint

    else if (b == c) {
        covered = d-a;
    }

    else if (d == a) {
        covered = b-c;
    }

    else if (a == c) {
        covered = max(b, d) - a;
    }

    else if (b == d) {
        covered = d - min(a,c);
    }

    
    /* instead of if conditions :
    
    1.) calculate overlap
    2.) find total distance painted
    3.) subtract overlap

    
    int overlap = max(0, min(b,d) - max(a,c));   // find the two closest points, if their difference is negative, they dont overlap, if its positive, they overlap (1)
    int covered = (b-a) + (d-c) - overlap;       // calculate the total distance and subtract the overlap. (2, 3)
    
    */

    fout << covered << endl;

    fin.close();
    fout.close();
}