// incomplete
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("marathon.in");
    ofstream fout("marathon.out");

    int n;
    fin >> n;
    vector< vector<int> > coordinates(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        fin >> x >> y;
        coordinates.at(i).at(0) = x;
        coordinates.at(i).at(1) = y;  
    }

    int prev_x = coordinates.at(0).at(0);
    int prev_y = coordinates.at(0).at(1);

    vector<int> distances(0);
    
    for (int i = 1; i < n; i++) {
        int x = coordinates.at(i).at(0);
        int y = coordinates.at(i).at(1);
        distances.push_back(abs(x - prev_x) + abs(y - prev_y));        
        prev_x = x;
        prev_y = y;
    }

    int max = 0;
    int max_index = 0;

    for (int i = 0; i < distances.size(); i++) {
        if (distances.at(i) > max) {
            max_index = i;
            max = distances.at(i);
        }
    }

    if (max_index == 0) {
        coordinates.erase(coordinates.begin() + 1);
    }
    else if (max_index == distances.size()-1) {
        coordinates.erase(coordinates.begin() + coordinates.size()-2);
    }
    else {
        if (distances.at(max_index - 1) > distances.at(max_index + 1)) {
            coordinates.erase(coordinates.begin() + max_index);
        }
        else {
            coordinates.erase(coordinates.begin() + max_index + 1);
        }
    }

    prev_x = coordinates.at(0).at(0);
    prev_y = coordinates.at(0).at(1);

    int total = 0;
    
    for (int i = 1; i < coordinates.size(); i++) {
        int x = coordinates.at(i).at(0);
        int y = coordinates.at(i).at(1);
        total += (abs(x - prev_x) + abs(y - prev_y));        
        prev_x = x;
        prev_y = y;
    }
     
    fout << total << endl;
}