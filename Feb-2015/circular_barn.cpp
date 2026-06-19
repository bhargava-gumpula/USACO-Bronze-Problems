#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");


    int count;
    fin >> count;
    vector<int> rooms(0);

    for (int i = 0; i < count; i++) {
        int temp;
        fin >> temp;

        rooms.push_back(temp);
    }
    int min_dist = 1e9; 
    for (int j = 0; j < rooms.size(); j++) {
        int total_dist = 0;

        for (int i = j; i < rooms.size(); i++) {

            total_dist += (i-j)*rooms[i];
            

            if (i == rooms.size()-1) {
            for (int x = 1; x <= j; x++) {
                total_dist += rooms[x-1] * (i-j+x);
            }
            }
        }
        min_dist = min(min_dist, total_dist);
    }

    fout << min_dist << endl;

    fin.close();
    fout.close();
}