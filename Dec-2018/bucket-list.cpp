#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main () {

    ifstream fin("blist.in");
    ofstream fout("blist.out");

    int n;
    fin >> n;
    vector<int> times(1000);
    for (int i = 0; i < 1000; i++) {
        times.at(i) = 0;
    }

    for (int i = 0; i < n; i++) {
        int start;
        int end;
        int buckets;

        fin >> start >> end >> buckets;
        start -= 1;
        end -= 1;

        for (int j = start; j <= end; j++) {
            times.at(j) += buckets;
        }
    }

    int max_buckets = 0;
    for (int i = 0; i < 1000; i++) {
        if (times.at(i) > max_buckets){
            max_buckets = times.at(i);
        }
    }

    fout << max_buckets << endl;

    fin.close();
    fout.close();
}