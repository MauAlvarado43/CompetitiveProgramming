#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int solve(int n) {

    queue<int> q;
    vector<int> v(1000000, 0);

    q.push(n);

    while(!q.empty()) {

        int temp = q.front();
        q.pop();

        if(temp == 0)
            return v[0];

        if(v[temp - 1] == 0) {
            q.push(temp - 1);
            v[temp - 1] = v[temp] + 1;
        }

        // for(ll i = 2; i <= temp / 2; i++) {

        //     if(temp % i == 0) {

        //         ll aux = max(i, temp / i);

        //         if(v[aux] == 0) {
        //             q.push(aux);
        //             v[aux] = v[temp] + 1;
        //         }

        //     }     

        // }

        for(int i = 2; i <= sqrt(temp); i++) {
            if(temp % i == 0 && v[temp / i] == 0) {
                q.push(temp / i);
                v[temp / i] = v[temp] + 1;
            }
        }        

    }

    return v[0];

}

int main() {

    // ios_base::sync_with_stdio(0);cin.tie(0);
    // auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while(t--) {
        
        int n;
        cin >> n;

        cout << solve(n) << "\n";

    }

    // auto end = chrono::high_resolution_clock::now();
    // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time_taken *= 1e-9;
    // cout << time_taken << setprecision(9) << "\n";

    return 0;

}