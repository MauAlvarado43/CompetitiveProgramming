#include <bits/stdc++.h>
#include <chrono>
#include <stdio.h>

#define ll long long int

using namespace std;

ll count1s(ll n) {

    ll count = 0;
        
    while(n) {
        count += n & 1;
        n >>= 1;
    }

    return count;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> players(m + 1);

    for(int i = 0; i < m + 1; i++) 
        cin >> players[i];

    ll ans = 0;

    for(int i = 0; i < m; i++) 
        if(count1s(players[i] ^ players[m]) <= k)
            ans++;

    cout << ans << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}