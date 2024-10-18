#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

ll binpow(ll a, ll b) {

    ll ans = 1;

    while(b) {
        if(b & 1) ans = ans * a;
        a *= a;
        b >>= 1;
    }

    return ans;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    // auto start = chrono::high_resolution_clock::now();

    ll a = 2, b = 20;

    cout << binpow(a, b) << endl;    

    // auto end = chrono::high_resolution_clock::now();
    // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time_taken *= 1e-9;
    // cout << time_taken << setprecision(9) << "\n";

    return 0;

}