#include <bits/stdc++.h> 

using namespace std;

void solve(int t) {

    int x, y, z;
    cin >> x >> y >> z;

    cout << "Case " << t << ": " << max(min(x, y), min(max(x, y), z)) << "\n";

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