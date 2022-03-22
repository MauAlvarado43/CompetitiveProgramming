#include <bits/stdc++.h> 

using namespace std;

void solve() {

    long long int n, k;
    cin >> n >> k;

    long long int res = (((k - 1) / (n - 1)) * n) + ((k - 1) % (n - 1)) + 1;

    cout << res << "\n";

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