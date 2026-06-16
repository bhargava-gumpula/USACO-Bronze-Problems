#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
bool compareFirst(const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
}
int main (void) {
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");

    int cow_count;
    fin >> cow_count;

    vector<vector<int> > cows(0);

    for (int i = 0; i < cow_count; i++) {
        int initial;
        int speed;
        
        fin >> initial >> speed;
        vector<int> temp;
        temp.push_back(initial);
        temp.push_back(speed);
        cows.push_back(temp);
    }

    sort(cows.begin(), cows.end(), compareFirst);

    int first_speed = cows.at(0).at(1);
    int group_count = 1;

    for (int i = 1; i < cow_count; i++) {
        if (cows.at(i).at(1) <= first_speed) {
            group_count ++;
            first_speed = cows.at(i).at(1);
        }
    }
    fout << group_count << endl;
    fin.close();
    fout.close();

}