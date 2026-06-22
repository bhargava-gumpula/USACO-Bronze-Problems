#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

vector<vector<bool>> swap_shells(vector<vector<bool> > states, int shell1, int shell2) {
    shell1 --;
    shell2 --;
    for (int i = 0; i < 3; i++) {    
        bool temp = states.at(i).at(shell1);
        states.at(i).at(shell1) = states.at(i).at(shell2);
        states.at(i).at(shell2) = temp;
    }
    return states;
}

vector<int> guess_shell(vector<vector<bool> > states, vector<int> scores, int guess) {
    for (int i = 0; i < 3; i++) {
        if (states.at(i).at(guess-1) == true) {
            scores.at(i) ++;
        }
    }
    return scores;
}


int main () {
    ifstream fin("shell.in");
    ofstream fout("shell.out");


    int n;
    fin >> n;


    vector<vector<bool> > states;
    vector<int> scores = {0, 0, 0};
    vector<bool> temp;

    states.push_back({true,false,false});
    states.push_back({false, true, false});
    states.push_back({false, false, true});

    for (int i = 0; i < n; i++) {
        int shell1;
        int shell2;
        int guess;

        fin >> shell1 >> shell2 >> guess;

        states = swap_shells(states, shell1, shell2);
        scores = guess_shell(states, scores, guess);
    }

    fout << max(max(scores.at(0), scores.at(1)), scores.at(2)) << endl;

    fin.close();
    fout.close();
}