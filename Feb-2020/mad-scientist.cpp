// incomplete
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
    ifstream fin ("breedflip.in");
    ofstream fout ("breedflip.out");

    int n;
    fin >> n;

    string temp_a;
    string temp_b;

    fin >> temp_a;
    fin >> temp_b;

    vector<char> a(n);
    vector<char> b(n);

    for (int i = 0; i < n; i++) {
        a.at(i) = temp_a[i];
        b.at(i) = temp_b[i];
    }

    bool flip = false;
    int flip_count = 0;
    for (int i = 0; i < n; i++) {

        if ((a.at(i) == 'G' && b.at(i) == 'H') || (a.at(i) == 'H' && b.at(i) == 'G')) {
            flip = true;
        }

        else if ((a.at(i) == 'H' && b.at(i) == 'H') || (a.at(i) == 'G' && b.at(i) == 'G')) {
            
            if (flip) {
                flip_count ++;
            }
            flip = false;
        }
    }

    fout << flip_count << endl;

    fin.close();
    fout.close();
}