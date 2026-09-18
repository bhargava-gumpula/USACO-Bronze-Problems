// incomplete
#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    // read inputs

    int n;
    cin >> n;

    string cows_temp;
    cin >> cows_temp;
    vector<int> reach(n);
    vector<char> cows(n);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        reach.at(i) = temp-1;

        cows.at(i) = cows_temp[i];
    }

    // find first and last occurence of g and h
    int first_g = 1e9;
    int last_g = 0;

    int first_h = 1e9;
    int last_h = 0;

    for (int i = 0; i < n; i++) {
        if (cows.at(i) == 'G') {
            first_g = min(first_g, i);
            last_g = max(last_g, i);
        }
        if (cows.at(i) == 'H') {
            first_h = min(first_h, i);
            last_h = max(last_h, i);
        }
    }


    unordered_set<int> h_leaders(0);
    unordered_set<int> g_leaders(0);


    /* at this point we have : 
        - cows vector containing each letter
        - reach vector containing distance each cow can reach
        - number of cows
        - first position of g and h
        - last position of g and h
    */


    /*  if first g reaches until last g, its a leader
        if first h reaches until last h, its a leader

        if first cow is g and reaches until h leader, it is also a leader
        if first cow is h and reaches until g leader, it is also a leader
    
    */
    
    int g_leader = -1;
    int h_leader = -1;

    if (reach[first_g] >= last_g) {
        g_leaders.insert(first_g);
        g_leader = first_g;
    }

    if (reach[first_h] >= last_h) {
        h_leaders.insert(first_h);
        h_leader = first_h;
    }

    for (int i = 0; i < n; i++) {
        if (cows.at(i) == 'H') {            // if the cow is a holestein
            if (h_leaders.count(i) == 0) {  // if the cow is not a leader
                if (g_leader != -1 && i <= g_leader && reach[i] >= g_leader) {
                    h_leaders.insert(i);
                }
            }
        }

        else if (cows.at(i) == 'G') {       // if the cow is a guernsey
            if (g_leaders.count(i) == 0) {  // if the cow is not a leader
                if (h_leader != -1 && i <= h_leader && reach[i] >= h_leader) {
                    g_leaders.insert(i);
                }
            }
        }
    }

    // return pairs of leader so multiply amount of g leader with amount of h leaders
    cout << h_leaders.size() * g_leaders.size() << endl;

}