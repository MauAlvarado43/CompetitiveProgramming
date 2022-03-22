#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int solveRecursive(vector<int>& denom, int n, int bills, int i) {

    if(n == 0) 
        return bills;

    if(i == denom.size())
        return -1;

    return solveRecursive(denom, n % denom[i], bills + (n / denom[i]), i + 1);
}

int solveDP() {

    // ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    vector<ll> denom = {1, 5, 10, 20, 100};
    ll n;
    cin >> n;

    ll dp[n + 1] = {};

    ll ans = 0;

    dp[0] = 0;

    for (ll i = 1; i <= n; i++) 
        dp[i] = LONG_LONG_MAX;
    
    for (ll i = 1; i <= n; i++)
        for (ll j = 0; j < denom.size(); j++) 
            if (dp[i - denom[j]] < LONG_LONG_MAX  && denom[j] <= i)
                dp[i] = min(dp[i], dp[i - denom[j]] + 1);

    return dp[n];

}

int solveGreedy(vector<int>& denom, int n) {

    int ans = 0;

    for (int i = 0; i < denom.size(); i++) {
        ans += n / denom[i];
        n %= denom[i];
    }

    return ans;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    vector<int> denom = {100, 20, 10, 5, 1};
    int n;
    cin >> n;

    cout << solveGreedy(denom, n) << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}