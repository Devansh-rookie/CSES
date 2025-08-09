#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    vector<string> words(N);
    for (int i = 0; i < N; ++i) cin >> words[i];

    unordered_map<string, int> freq;            // substring → occurrence count

    // Step 1: count every substring of length ≥ 3
    for (const string &w : words) {
        int L = static_cast<int>(w.size());
        for (int i = 0; i < L; ++i)
            for (int len = 3; i + len <= L; ++len)
                ++freq[w.substr(i, len)];
    }

    // Step 2–3: collect recurring substrings and turn each into its next permutation
    vector<string> result;
    result.reserve(freq.size());
    for (auto &kv : freq) {
        if (kv.second < 2) continue;            // not recurring
        string s = kv.first;
        string t = s;
        if (!next_permutation(t.begin(), t.end()))
            t = s;                              // already last permutation
        result.push_back(t);
    }

    // Step 4: sort and output
    sort(result.begin(), result.end());
    for (size_t i = 0; i < result.size(); ++i) {
        if (i) cout << ' ';
        cout << result[i];
    }
    return 0;
}

// 4 hakuna kunafa kubernetes fridge
// 2 pineapple beriberi
