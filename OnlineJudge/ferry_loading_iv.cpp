#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void solve() {

    int l, m;
    cin >> l >> m;

    queue<double> left;
    queue<double> right;

    double cars = l;
    int times = 0;

    bool isLeft = true;

    for(int i = 0; i < m; i++) {

        double _size;
        cin >> _size;

        string s;
        cin >> s;

        if(s == "left") left.push(_size / 100);
        else right.push(_size / 100);

    } 

    while(!left.empty() || !right.empty()) {

        if(isLeft) {

            while(left.size() && cars > left.front()) {
                cars -= left.front();
                left.pop();
            }

        } else {

            while(right.size() && cars > right.front()) {
                cars -= right.front();
                right.pop();
            }

        }

        isLeft = !isLeft;
        cars = l;
        times++;

    }

    cout << times << "\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while(t--)
        solve();

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}