// incomplete
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, f;
    string c;

    cin >> n >> f >> c;

    unordered_map<string, int> moos;

    for (int i = 0; i < n - 2; i++) {
        if (c[i] != c[i + 1] && c[i + 1] == c[i + 2]) {
            moos[string(1, c[i]) + c[i + 1] + c[i + 2]]++;
        }
    }

    unordered_map<string, int> best = moos;

    for (int i = 0; i < n; i++) {
        for (int letter = 0; letter < 26; letter++) {
            char curr = 'a' + letter;

            if (curr == c[i]) {
                continue;
            }

            unordered_map<string, int> saved;

            auto change = [&](const string& key, int amount) {
                if (!saved.count(key)) {
                    saved[key] = moos[key];
                }

                moos[key] += amount;
            };

            // Remove old left triple
            if (i >= 2) {
                if (c[i - 2] != c[i - 1] && c[i - 1] == c[i]) {
                    string key =
                        string(1, c[i - 2]) + c[i - 1] + c[i];

                    change(key, -1);
                }
            }

            // Remove old middle triple
            if (i >= 1 && i + 1 < n) {
                if (c[i - 1] != c[i] && c[i] == c[i + 1]) {
                    string key =
                        string(1, c[i - 1]) + c[i] + c[i + 1];

                    change(key, -1);
                }
            }

            // Remove old right triple
            if (i + 2 < n) {
                if (c[i] != c[i + 1] && c[i + 1] == c[i + 2]) {
                    string key =
                        string(1, c[i]) + c[i + 1] + c[i + 2];

                    change(key, -1);
                }
            }

            // Add new left triple
            if (i >= 2) {
                if (c[i - 2] != c[i - 1] && c[i - 1] == curr) {
                    string key =
                        string(1, c[i - 2]) + c[i - 1] + curr;

                    change(key, 1);
                }
            }

            // Add new middle triple
            if (i >= 1 && i + 1 < n) {
                if (c[i - 1] != curr && curr == c[i + 1]) {
                    string key =
                        string(1, c[i - 1]) + curr + c[i + 1];

                    change(key, 1);
                }
            }

            // Add new right triple
            if (i + 2 < n) {
                if (curr != c[i + 1] && c[i + 1] == c[i + 2]) {
                    string key =
                        string(1, curr) + c[i + 1] + c[i + 2];

                    change(key, 1);
                }
            }

            // Update the best resulting counts
            for (const auto& [key, original] : saved) {
                best[key] = max(best[key], moos[key]);
            }

            // Restore the original counts
            for (const auto& [key, original] : saved) {
                moos[key] = original;
            }
        }
    }

    vector<string> possibles;

    for (const auto& [key, value] : best) {
        if (value >= f) {
            possibles.push_back(key);
        }
    }

    sort(possibles.begin(), possibles.end());

    cout << possibles.size() << '\n';

    for (const string& possible : possibles) {
        cout << possible << '\n';
    }
}
