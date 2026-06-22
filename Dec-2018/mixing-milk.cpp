#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<int>> pour (vector<vector<int>> buckets, int bucket1, int bucket2) {
    // bucket 1 = 10 3
    // bucket 2 = 11 4
    // bucket 3 = 12 5

    int bucket1_size = buckets.at(bucket1).at(0);
    int bucket1_content = buckets.at(bucket1).at(1);

    int bucket2_size = buckets.at(bucket2).at(0);
    int bucket2_content = buckets.at(bucket2).at(1);


    if (bucket1_content + bucket2_content <= bucket2_size) {
        buckets.at(bucket2).at(1) = bucket2_content + bucket1_content;
        buckets.at(bucket1).at(1) = 0;
    }

    else if (bucket1_content + bucket2_content > bucket2_size) {
        buckets.at(bucket1).at(1) -= bucket2_size - bucket2_content;
        buckets.at(bucket2).at(1) = bucket2_size;
    } 


    return buckets;

}


int main() {


    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");



    vector<vector<int>> buckets;

    for (int i = 0; i < 3; i++) {
        int limit;
        int content;

        fin >> limit >> content;

        buckets.push_back({limit, content});
    }

    for (int i = 0; i < 33; i ++) {
        buckets = pour(buckets, 0, 1);
        buckets = pour(buckets, 1, 2);
        buckets = pour(buckets, 2, 0);
    }
    buckets = pour(buckets, 0, 1);

    for (int i = 0; i < 3; i ++) {
        fout << buckets.at(i).at(1) << endl;
    }

    fin.close();
    fout.close();

}