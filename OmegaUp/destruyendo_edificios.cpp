#include <bits/stdc++.h> 
using namespace std;

#define ll long long int

int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> heights(n);
    for (ll i = 0; i < n; i++) cin >> heights[i];

    stack<ll> buildings;
    ll max_area = 0;

    for (ll i = 0; i <= n; i++) {

        ll height = (i == n) ? 0 : heights[i];

        while (!buildings.empty() && heights[buildings.top()] > height) {
            
            ll h = heights[buildings.top()];
            buildings.pop();

            ll width = (buildings.empty()) ? i : i - buildings.top() - 1;
            max_area = max(max_area, h * width);

        }

        buildings.push(i);

    }

    cout << max_area << "\n";

    return 0;

}