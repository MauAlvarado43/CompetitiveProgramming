#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n; cin >> n;
    vector<int> roads(n - 1);
    vector<int> stations(n);
    vector<ll> leftRight(n), rightLeft(n);

    for(int i = 0; i < n - 1; i++) cin >> roads[i];
    for(int i = 0; i < n; i++) cin >> stations[i];

    leftRight[0] = stations[0];
    rightLeft[n - 1] = stations[n - 1];

    for(int i = 1; i < n; i++) {
        leftRight[i] = leftRight[i - 1] + stations[i] + roads[i - 1];
        rightLeft[n - i - 1] = rightLeft[n - i] + stations[n - i - 1] + roads[n - i - 1];
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ll value = abs(leftRight[i] - rightLeft[i]);
        if(value <= stations[i]) {
            cout << stations[i] - value << "\n";
            return 0;
        }
    }

    cout << "0\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}