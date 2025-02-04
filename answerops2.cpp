#include<bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}


int main() {
    int n; 
    setIO("check");
    cin >> n;
    vector<string> names(n); 
    vector<double> handsomeness(n), intelligence(n), richness(n); 

    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> handsomeness[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> intelligence[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> richness[i];
    }

    double maxScore = -1.0;
    string bestGuy;

    for (int i = 0; i < n; ++i) {
        double totalScore = handsomeness[i] + intelligence[i] + richness[i];
        if (totalScore > maxScore) {
            maxScore = totalScore;
            bestGuy = names[i];
        }
    }

    cout << bestGuy << endl;

    return 0;
}
