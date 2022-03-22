#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void solve() {

    int n, l, r, k;
    cin >> n >> l >> r >> k;

    vector<int> chocolates(n);

    for(int i = 0; i < n; i++) 
        cin >> chocolates[i];

    sort(chocolates.begin(), chocolates.end());

    int ans = 0;

    for(int i = 0; i < n; i++) {

        if((chocolates[i] < l || chocolates[i] > r)) 
            continue;
        
        if(chocolates[i] <= k) {
            k -= chocolates[i];
            ans++;
        }
        else {
            break;
        }

    }  

    cout << ans << "\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int tt;
    cin >> tt;

    while(tt--)
        solve();

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}