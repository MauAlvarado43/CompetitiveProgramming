#include <bits/stdc++.h> 

using namespace std;

void solve() {
    
    vector<int> a(3);
    int m;

    cin >> a[0] >> a[1] >> a[2] >> m;
    sort(a.begin(), a.end());

    m -= abs(a[2] - a[1]) + abs(a[2] - a[0]);

    if(m >= 0 && m % 3 == 0) cout << "YES\n";
    else cout << "NO\n";

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