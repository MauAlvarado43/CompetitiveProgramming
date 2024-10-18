#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

ll gcd(ll a, ll b) {
    if(!a || !b) return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while(b);
    return a << shift;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    ll t; cin >>  t;
    
    while(t--) {
        ll a, b; cin >> a >> b;
        cout << gcd(a, b) << " " << lcm(a, b) << "\n";
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}