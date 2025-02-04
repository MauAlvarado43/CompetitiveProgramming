#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void solve() {

    int n, t, m;
    cin >> n >> t >> m;

    queue<pair<int, int>> left, right;
    vector<int> cars(m);

    for(int i = 0; i < m; i++) {

        int arrival_time;
        cin >> arrival_time;

        string side;
        cin >> side;

        if(side == "left") left.push({ arrival_time, i });
        else right.push({ arrival_time, i });

    }

    int current_time = 0;
    bool is_left = true;

    while(!left.empty() || !right.empty()) {

        int next_time = INT_MAX;

        if(!left.empty())
            next_time = min(next_time, left.front().first);
            
        if(!right.empty())
            next_time = min(next_time, right.front().first);

        current_time = max(current_time, next_time);

        int loaded = 0;

        if(is_left) {

            while(!left.empty() && left.front().first <= current_time && loaded < n) {
                cars[left.front().second] = current_time + t;
                left.pop();
                loaded++;
            }

        } 
        else {

            while(!right.empty() && right.front().first <= current_time && loaded < n) {
                cars[right.front().second] = current_time + t;
                right.pop();
                loaded++;
            }

        }

        current_time += t;
        is_left = !is_left;

    }

    for(int i = 0; i < cars.size(); i++) 
        cout << cars[i] << "\n"; 

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
        if(tt > 0) cout << "\n";
    } 

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}