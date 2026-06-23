#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {

    ifstream fin("balancing.in");
    ofstream fout("balancing.out");


    vector<vector<int> > cows;
    int n; 
    int b;



    fin >> n >> b;
    for (int i = 0; i < n; i++){
        int x;
        int y;

        fin >> x >> y;
        vector<int> temp(0);
        temp.push_back(x);
        temp.push_back(y);

        cows.push_back(temp);
    } 



    int fence_x;
    int fence_y;

    int min_cows = 1e9;
    for (auto a : cows) {
        fence_x = a[0]+1;
        for (auto a : cows) {
            fence_y = a[1] + 1;
            int count1 = 0;
            int count2 = 0;
            int count3 = 0;
            int count4 = 0;

            for (auto a : cows) {
                if (a[0] < fence_x && a[1] < fence_y) {
                    count1 ++;
                }
                if (a[0] < fence_x && a[1] > fence_y) {
                    count3 ++;
                }
                if (a[0] > fence_x && a[1] < fence_y) {
                    count2 ++;
                }
                if (a[0] > fence_x && a[1] > fence_y) {
                    count4 ++;
                }
            }  
            min_cows = min(max(max(count1, count2), max(count3, count4)), min_cows);  
        }
    }
    fout << min_cows << endl;

    fin.close();
    fout.close();
}