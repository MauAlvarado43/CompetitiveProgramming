#include <bits/stdc++.h>
#include <chrono>

#define ll long long int
#define vvll vector<vector<ll>>
#define MOD 1000000007

using namespace std;

// fn = fn-1 + fn-2, where f0 = 0 and f1 = 1, k >= 2
// Sn = sum(fi, i = 1 to n) 
// We know that fn+2 = fn+1 + fn -> fn = fn+2 - fn+1
// So we can use this to find the sum of fibonacci numbers
// Sn = sum(fn+2 - fn+1, i = 1 to n) = (f3 - f2) + (f4 - f3) + (f5 - f4) + ... + (fn+1 - fn) + (fn+2 - fn+1)
//    = fn+2 - f2 = fn+2 - 1

vvll multiply(vvll A, vvll B) {

    int l = A.size();
    int m = A[0].size();
    int n = B[0].size();

    vvll C(l, vector<ll>(n, 0));

    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;

    return C;

}

ll fib(ll n) {

    vvll a = {{0,1} , {1,1}};
    vvll ans = {{1, 0}, {0, 1}};

    while(n) {
        if(n & 1) ans = multiply(ans, a);
        a = multiply(a, a);
        n >>= 1;
    }

    return ans[0][1] % MOD;

}

ll fibosum(ll n, ll m) {
    return (fib(m + 2) - fib(n + 1) + MOD) % MOD;
}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    ll a, b, t, ans;
    cin >> t;

    while(t--) {
        cin >> a >> b;
        ans = fibosum(a % MOD, b % MOD);
        cout << ans << "\n";
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}