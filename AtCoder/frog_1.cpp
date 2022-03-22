#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n;
    cin >> n;

    vector<int> stones(n);
    vector<int> dp(n);

    for(int i = 0; i < n; i++) 
        cin >> stones[i];
    
    dp[0] = 0;
    dp[1] = abs(stones[1] - stones[0]);

    for(int i = 2; i < n; i++) 
        dp[i] = min(dp[i - 1] + abs(stones[i] - stones[i - 1]), dp[i - 2] + abs(stones[i] - stones[i - 2]));
    
    cout << dp[n - 1] << "\n";


    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}