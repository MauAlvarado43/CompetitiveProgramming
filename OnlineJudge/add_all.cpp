#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void solve(ll n) {

    priority_queue<ll, vector<int>, greater<int>> pq;

    ll cost = 0, x, y;
    
    for(int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1) {

        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();

        cost += x + y;
        pq.push(x + y);
    
    }

    cout << cost << "\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    ll tt;
    cin >> tt;

    while(tt) {
        solve(tt);
        cin >> tt;
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}