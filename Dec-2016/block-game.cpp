#include <stdio.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

int main () {

    ifstream fin ("blocks.in");
    ofstream fout ("blocks.out");

    int n; 
    fin >> n;

    vector<int> letter_count(26);
    vector<int> temp_letter_count(26);

    for (int i = 0; i < 26; i++) {
        letter_count.at(i) = 0;
        temp_letter_count.at(i) = 0;
    }

    for (int i = 0; i < n; i ++) {
        string word1;
        string word2;

        fin >> word1 >> word2;

        for (auto a : word1) {
             temp_letter_count.at(a- 97) ++;
        }

        for (int i = 0; i < 26; i++) {
            letter_count.at(i) += temp_letter_count.at(i);
        }

        for (auto a: word2) {
            temp_letter_count.at(a - 97) --;
        }

        for (int i = 0; i < 26; i++) {
            if (temp_letter_count.at(i) < 0) {
                letter_count.at(i) += abs(temp_letter_count.at(i));
            }
        }

        for (int i = 0; i < 26; i++) {
            temp_letter_count.at(i) = 0;
        }
    }
    for (int i = 0; i < 26; i++) {
        fout << letter_count.at(i) << endl;
    }

    fin.close();
    fout.close();
}