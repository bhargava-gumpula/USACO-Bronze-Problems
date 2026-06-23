#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main () {

    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");

    int fj;
    int bessie;

    fin >> fj >> bessie;

    if (fj == bessie) {
        fout << 0 << endl;
        return 1;
    }

    bool right = true;
    int total_steps = 0;
    int steps = 1;
    for (int i = 0; i < 9*abs(fj-bessie); i++) {
        if (right == true) {
            if (fj < bessie && fj + steps >= bessie) {
                total_steps += steps;
                total_steps -= fj+steps-bessie;
                break;
            }

            right = false;

        }
        else if (right == false) {
            if (fj > bessie && fj - steps <= bessie) {
                total_steps += steps;
                total_steps -= bessie - (fj - steps);
                break;
            }

            right = true;
        }
        
        total_steps += steps*2;
        steps *= 2;
    }

    fout << total_steps << endl;

    fin.close();
    fout.close();
}