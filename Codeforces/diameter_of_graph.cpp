#include <bits/stdc++.h> 

using namespace std;

void solve() {

    long long int n, m, k;
    cin >> n >> m >> k;

    long long int s = n + ((n * (n - 3)) / 2);

    if(m > s) {
        cout << "NO\n";
    }
    else if(m < n - 1) {
        cout << "NO\n";
    }
    else if(k - 2 == 0) {
        if(n == 1) cout << "YES\n";
        else cout << "NO\n";
    }
    else if(k - 2 == 1) {
        if(m == s) cout << "YES\n";
        else cout << "NO\n";
    }
    else if(k < 2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
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