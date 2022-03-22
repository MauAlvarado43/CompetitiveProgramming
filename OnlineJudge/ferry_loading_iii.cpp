#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void solve() {

    int n, t, m;
    cin >> n >> t >> m;

    int time = 0;
    bool isLeft = true;

    queue<pair<int, int>> left;
    queue<pair<int, int>> right;
    vector<int> cars(m);

    for(int i = 0; i < m; i++) {

        int _t;
        cin >> _t;

        string s;
        cin >> s;

        if(s == "left") 
            left.push({_t, i});
        else 
            right.push({_t, i});

    }    

    while(!left.empty() || !right.empty()) { 

        int curr = 0;
        time = max(time, min(left.empty() ? INT_MAX : left.front().first, right.empty() ? INT_MAX : right.front().first));

        if(isLeft) {

            while(!left.empty() && left.front().first <= time && curr < n) {

                cars[left.front().second] = time + t;
                left.pop();
                curr++;

            }

        }
        else {

            while(!right.empty() && right.front().first <= time && curr < n) {
                
                cars[right.front().second] = time + t;
                right.pop();
                curr++;

            }  

        }

        time += t;
        isLeft = !isLeft;

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

        if(tt > 0)
            cout << "\n";
            
    } 

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}