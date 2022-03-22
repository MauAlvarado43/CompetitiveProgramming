#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    ll n, k;
    cin >> n >> k;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    
    for(int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        pq.push(x);
    }

    int ans = 0;

    while(pq.size() > 1 && pq.top() < k) {
        
        ll a = pq.top();
        pq.pop();

        ll b = pq.top();
        pq.pop();

        pq.push(a + (2 * b));
        
        ans++;
        
    }

    if(pq.top() < k)
        cout << -1 << "\n";
    else 
        cout << ans << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}