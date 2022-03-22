#include <bits/stdc++.h> 

using namespace std;

void solve() {
        
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    vector<int> arr = {a, b, c};
    sort(arr.begin(), arr.end());

    if(a + b + c - 3 < m)
        cout << "NO\n";
    else if(arr[2] - arr[1] - arr[0] - 1 > m)
        cout << "NO\n";
    else 
        cout << "YES\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n = 0;
    cin >> n;

    while(n > 0) {
        solve();
        n--;
    }

    return 0;

}