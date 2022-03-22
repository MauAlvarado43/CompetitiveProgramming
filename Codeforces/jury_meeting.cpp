#include <bits/stdc++.h> 
#define ll long long int

using namespace std;

ll factorial(ll n, int k) {
 
    if(n == 1)
        return 1;

    if(n == k)
        return 1 * factorial(n - 1, k) % 998244353;
 
    return n * factorial(n - 1, k) % 998244353;
}

void solve() {

    ll n;
    cin >> n;

    vector<ll> numbers(n);
    for(ll&x : numbers) cin >> x;

    int nMax = *max_element(numbers.begin(), numbers.end());
    int maxCount = count(numbers.begin(), numbers.end(), nMax);
    int k = count(numbers.begin(), numbers.end(), nMax - 1) + 1;

    int ans = factorial(n, 0);
    int exceptions = factorial(n, k);

    if(maxCount == 1) cout << (ans - exceptions + 998244353) % 998244353 << "\n"; 
    else cout << ans << "\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n;
    cin >> n;

    while(n > 0) {
        solve();
        n--;
    }

    return 0;

}