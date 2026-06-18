#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main () {
    ifstream fin("whatbase.in");
    ofstream fout("whatbase.out");
    int cases;
    fin >> cases;
    for (int t = 0; t < cases; t++) {
        string num1;
        string num2;
        fin >> num1;
        fin >> num2;


        unordered_map<int, int> nums; 
        int d0 = num1[0] - '0';  
        int d1 = num1[1] - '0';  
        int d2 = num1[2] - '0';

        for (int i = 10; i < 15001; i++) {
            int temp = d0 * i*i + d1 * i + d2;
            nums[temp] = i;
        }

        d0 = num2[0] - '0';  
        d1 = num2[1] - '0';  
        d2 = num2[2] - '0';

        for (int j = 10; j < 15001; j++) {
            int temp = d0 * j*j + d1 * j + d2;
            if (nums.count(temp)) {
                fout << nums[temp] << ' ' << j << endl;
                break;
            }
        }

    }
    fin.close();
    fout.close();
}