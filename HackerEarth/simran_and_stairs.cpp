#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int solve(int n, int i) {

    if(i > n) 
        return 0;

    if(i == n)
        return 1;

    return solve(n, i + 1) + solve(n, i + 2) + solve(n, i + 3);

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n; 
    cin >> n;   

    cout << solve(n, 0) << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}