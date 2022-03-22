#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto it = upper_bound(v.begin(), v.end(), 5) - v.begin();
    auto it2 = lower_bound(v.begin(), v.end(), 5) - v.begin();

    cout << v[it] << "\n";
    cout << v[it2] << "\n";

    int n, q;
    cin >> n >> q;

    vector<vector<int>> letters(26, vector<int>());

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        letters[x - 'a'].push_back(i);
    }

    while(q--) {

        int i, j, k;
        cin >> i >> j >> k;

        if(k) {

            for(int l = 0; l < 26; l++) {
                
            }

        } 
        else {

        }

    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}