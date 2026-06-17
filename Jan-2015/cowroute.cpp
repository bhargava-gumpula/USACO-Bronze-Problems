#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


int main () {

    ifstream fin("cowroute.in");
    ofstream fout("cowroute.out");

    int a;
    int b;
    int n;
    fin >> a >> b >> n;

    int min_cost = 1e9;

    for (int i = 0; i < n; i ++) {
        int cost;
        int city_count;
        vector<int> v;
        int temp;

        fin >> cost >> city_count;
        
        for (int j = 0; j < city_count; j++) {
            fin >> temp;
            v.push_back(temp);
        }

        bool found = false;
        for (int j = 0; j < v.size(); j++) {
            if (v.at(j) == a) {
                found = true;
            }
            if (found && v.at(j) == b) {
                min_cost = min(min_cost, cost);
            }
        }
    }
    if (min_cost == 1e9) {
        fout << -1 << endl;
    }
    else {
        fout << min_cost << endl;
    }
    fin.close();
    fout.close();
}