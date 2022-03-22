#include <bits/stdc++.h> 

using namespace std;

void solve() {

    int n, s;
    cin >> n >> s;

    if(s >= n) {
        cout << (s / ((n / 2) + 1)) << "\n";
    }
    else {
        cout << (((n / 2) + 1 <= s) ? "1" : "0") << "\n"; 
    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    while(n > 0) {
        solve();
        n--;
    }

    return 0;

}