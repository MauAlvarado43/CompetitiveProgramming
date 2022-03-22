#include <bits/stdc++.h> 

using namespace std;

void solve(int t) {
    
    int k;
    cin >> k;
    
    double toPay = 0;

    vector<pair<char, int>> payments(k);
    for(pair<char,int>& x : payments) cin >> x.first >> x.second;

    int lines;
    cin >> lines;

    for(int i = 0; i <= lines; i++) {

        string s;
        getline(cin, s);

        for(int j = 0; j < k; j++) {
            for(int m = 0; m < s.length(); m++) {
                if(s[m] == payments[j].first) {
                    toPay += payments[j].second * 0.01;
                }
            }
        }

    }
    
    cout << fixed << setprecision(2) << toPay << "$\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;

}