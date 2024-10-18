#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    // int LIM = 31;
    int LIM = (5 * 10000) + 5;

    int k, p;
    cin >> k >> p;

    vector<int> ps(p);
    vector<int> dp(LIM, INT_MAX);

    for(int i = 0; i < p; i++) 
        cin >> ps[i];

    sort(ps.begin(), ps.end());

    dp[0] = 0;

    for(int i = 1; i < LIM; i++) {

        int aux = INT_MAX;

        for(int j = 0; j < p; j++) {

            int x = i - ps[j];

            // aux = min(abs(x), aux);
            
            if(x >= 0)
                aux = min(dp[x], aux);
            else
                aux = min(abs(x), aux);

        }

        dp[i] = aux;

    }

    // for(int i = 0; i < LIM; i++) 
    //     cout << dp[i] << " ";
    // cout << "\n";

    for(int i = 0; i < k; i++) {

        int q;
        cin >> q;

        cout << dp[q] << "\n";

    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}