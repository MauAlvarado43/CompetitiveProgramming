#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

bool solve(int n) {
    
    ll l = 0;
    ll r = n;

    while(r >= l) {

        ll m = (l + r) / 2;
        ll nn = m * m;

        if(nn == n)
            return true;
        else if(nn < n)
            l = m + 1;
        else
            r = m - 1;

    }

    return false;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    solve(3610000);

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}