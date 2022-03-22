#include <bits/stdc++.h> 
 
#define ll long long int
 
using namespace std;
 
void solve() {
 
    ll l, r;
    cin >> l >> r;
 
    if((r / 2) + 1 < l)
        cout << r % l << "\n";
    else
        cout << r - ((r / 2) + 1) << "\n";
 
}
 
int main() {
 
    ios_base::sync_with_stdio(0);cin.tie(0);
 
    ll tt;
    cin >> tt;
 
    while(tt > 0) {
        solve();
        tt--;
    }
 
    return 0;
 
}