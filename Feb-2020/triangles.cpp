#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

int main () {
    
    ifstream fin ("triangles.in");
    ofstream fout ("triangles.out");
    
    int n; 
    fin >> n;

    vector<pair<int, int>> points(0);
    for (int i = 0; i < n; i++) {
        int x;
        int y;
        fin >> x >> y;

        pair<int, int> temp = make_pair(x, y);
        points.push_back(temp);
    }

    double max_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                pair<int, int> point1 = points.at(i);
                pair<int, int> point2 = points.at(j);
                pair<int, int> point3 = points.at(k);
                double area = 0;

    
                if (point1.first == point2.first && point1.second == point3.second)
                    area = (double)abs(point2.second - point1.second) * abs(point3.first - point1.first);
                if (point1.first == point3.first && point1.second == point2.second)
                    area = (double)abs(point3.second - point1.second) * abs(point2.first - point1.first);
                if (point2.first == point1.first && point2.second == point3.second)
                    area = (double)abs(point1.second - point2.second) * abs(point3.first - point2.first);
                if (point2.first == point3.first && point2.second == point1.second)
                    area = (double)abs(point3.second - point2.second) * abs(point1.first - point2.first);
                if (point3.first == point1.first && point3.second == point2.second)
                    area = (double)abs(point1.second - point3.second) * abs(point2.first - point3.first);
                if (point3.first == point2.first && point3.second == point1.second)
                    area = (double)abs(point2.second - point3.second) * abs(point1.first - point3.first);

                max_area = max(max_area, area);
            }
        }
    }
    fout << (long long) max_area << endl;

    fin.close();
    fout.close();
}