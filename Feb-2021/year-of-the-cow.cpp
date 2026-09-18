#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <utility>

using namespace std;

int main () {
    int n;
    cin >> n;

    vector<string> animals = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    unordered_map<string, pair<int, string>> differences;
    differences["Bessie"] = {0, "Ox"};

    for (int i = 0; i < n; i++) {
        string cow1;
        string cow2;
        string relativity;
        string year;
        string temp;

        cin >> cow1;
        cin >> temp;
        cin >> temp;
        cin >> relativity;
        cin >> year;
        cin >> temp;
        cin >> temp;
        cin >> cow2;

        // we have cow1, cow2, relativity, and year
        /*        
        cout << cow1 << endl;
        cout << relativity << endl;
        cout << year << endl;
        cout << cow2 << endl;
        */

        int difference = 0;
        string cow1_year = year;
        string cow2_year = differences[cow2].second;

        int temp1;
        int temp2;

        
        for (int i = 0; i < 12; i++) {
            if (cow1_year == animals[i]) {
                temp1 = i;
            }
            if (cow2_year == animals[i]) {
                temp2 = i;
            }
        }

        if (relativity == "previous") {
            if (temp1 == temp2) {
                difference = 12;
            }
            else if (temp2 >= temp1) {
                difference = temp2 - temp1;
            }
            else {
                difference = temp2 + 12 - temp1;
            }
            differences[cow1].first = differences[cow2].first - difference;
        }

        else if (relativity == "next") {
            if (temp1 == temp2) {
                difference = 12;
            }
            else if (temp1 >= temp2) {
                difference = temp1 - temp2;
            }
            else {
                difference = temp1 + 12 - temp2;
            }
            differences[cow1].first = differences[cow2].first + difference;
        }

        
        differences[cow1].second = year;
    }

    cout << abs(differences["Elsie"].first) << endl;

}