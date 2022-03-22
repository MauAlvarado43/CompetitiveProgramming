#include <bits/stdc++.h> 
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n;
    cin >> n;

    // auto start = chrono::high_resolution_clock::now();

    stack<pair<ll, ll>> buildings;
    ll max_area = 0;

    for(ll i = 0; i <= n; i++) {
        
        ll height;
        
        if(i != n)
            cin >> height;
        else
            height = 0;

        if(buildings.empty()) {
            buildings.push(make_pair(height, i));
            max_area = height;
        }
        else if(buildings.top().first <= height) {
            buildings.push(make_pair(height, i));
        }
        else {

            ll j = buildings.size() - 1;
            ll k = 0;

            while(j >= 0 && buildings.top().first >= height) {
                
                pair<ll, ll> t = buildings.top();
                k = t.second;
                buildings.pop();

                max_area = max(t.first * (i - t.second), max_area);  
                j--;             

            }

            buildings.push(make_pair(height, k));

        }

    }        

    cout << max_area << "\n";
    
    // auto end = chrono::high_resolution_clock::now();
    // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time_taken *= 1e-9;
    // cout << time_taken << setprecision(9) << "\n";

    return 0;

}



// 7
// 4 5 4 3 3 3 3

// 7
// 2 1 4 5 1 3 3

// 5
// 5 4 3 2 1

// 5
// 1 2 3 4 5

// 1
// 2

// 5
// 5 5 5 5 5

// 7
// 1 2 3 4 3 2 1