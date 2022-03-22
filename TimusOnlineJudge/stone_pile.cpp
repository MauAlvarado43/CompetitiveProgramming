#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int solve(vector<int>& v, int dif, int i) {

    if(i == v.size()) 
        return abs(dif);

    return min(solve(v, dif + v[i], i + 1), solve(v, dif - v[i], i + 1));

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << solve(v, 0, 0) << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}