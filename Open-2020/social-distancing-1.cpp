// incomplete
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;



int one () {

}

int two () {
    
}

int three () {
    
}

int four () {
    
}

int five () {
    
}

int six () {
    
}

int seven () {
    
}


int main() {
    ifstream fin ("socdist1.in");
    ofstream fout ("socdist1.out");

    int n;
    fin >> n;

    string stalls;
    fin >> stalls;

    vector<int> counts(0);
    
    int min_count = 1000000000;
    int count = 0;

    for (int i = 0; i < n; i++){
        if (stalls.at(i) == '1') {
            counts.push_back(count);
            count = 0;
            continue;
        }
        count ++;
    }
    counts.push_back(count);

    for (int i = 1; i < (int)counts.size() - 1; i++) {
        min_count = min(min_count, counts.at(i));
    }

    vector<int> sorted_interior(counts.begin() + 1, counts.end() - 1);
    sort(sorted_interior.begin(), sorted_interior.end());

    int left_edge = counts.at(0);
    int right_edge = counts.at(counts.size()-1);

    int max_count = sorted_interior.empty() ? 0 : sorted_interior.back();
    int second_max = sorted_interior.size() >= 2 ? sorted_interior.at(sorted_interior.size() - 2) : 0;

    /*  we have : 
        - the smallest interior gap    (min_count)
        - the largest interior gap     (max_count)
        - the second largest interior  (second_max)
        - a vector of all the counts   (counts)
        - gap on the left              (left_edge)
        - gap on the right             (right_edge) 
    */

    if (min_count == 0) {
        fout << 0 << endl;
        return 0;
    }

    // left end, and largest
    int one = min(min(left_edge, max_count / 2), min_count);

    // right end and largest
    int two = min(min(right_edge, max_count / 2), min_count);

    // left end and right end
    int three = min(min(left_edge, right_edge), min_count);

    // largest and second largest
    int four = min(min(max_count / 2, second_max / 2), min_count);

    // both cows in largest gap
    int five = min(max_count / 3, min_count);

    // both cows on edge
    int six = left_edge > 0 ? min((left_edge - 1) / 2, min_count) : 0;
    int seven = right_edge > 0 ? min((right_edge - 1) / 2, min_count) : 0;

    fout << max(max(max(one, two), max(three, four)), max(max(five, six), seven)) + 1 << endl;

    fin.close();
    fout.close();
}