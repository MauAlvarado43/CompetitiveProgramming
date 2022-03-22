#include <bits/stdc++.h> 

using namespace std;

void solve(int n) {

    int x0, y0;
    cin >> x0 >> y0;

    for(int i = 0; i < n; i++) {

        int x, y;
        cin >> x >> y;

        if(x0 == x || y0 == y) {
            cout << "divisa" << "\n";
        }
        else if(x < x0 && y < y0) {
            cout << "SO" << "\n";
        }
        else if(x > x0 && y < y0) {
            cout << "SE" << "\n";
        }
        else if(x < x0 && y > y0) {
            cout << "NO" << "\n";
        }
        else if(x > x0 && y > y0) {
            cout << "NE" << "\n";
        }

    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    while(n != 0) {
        solve(n);
        cin >> n;
    }

    return 0;

}