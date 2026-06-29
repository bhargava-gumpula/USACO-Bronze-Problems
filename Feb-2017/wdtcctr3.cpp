#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {

    ifstream fin ("cowqueue.in");
    ofstream fout("cowqueue.out");



    int n;
    fin >> n;
    vector<pair<int, int>> cows(0);
    for (int i = 0; i < n; i++) {
        int arrive;
        int time;
        fin >> arrive >> time;

        cows.push_back({arrive, time});
    }
    
    sort(cows.begin(), cows.end());

    int time_passed = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            time_passed += cows.at(i).first;
        }
        
        time_passed += cows.at(i).second;

        if (i == n-1) {
            break;
        }



        if (time_passed < cows.at(i+1).first) {
            time_passed += cows.at(i+1).first - time_passed;
        }

    }

    fout << time_passed << endl;


    fin.close();
    fout.close();
}