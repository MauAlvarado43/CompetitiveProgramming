#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    double n, x0, y0;
    cin >> n >> x0 >> y0;

    set<double> arrows;

    for (int i = 0; i < n; i++) {

        double x, y, m;
        cin >> x >> y;

        if(x - x0 != 0)
            m = (y - y0) / (x - x0);
        else
            m = INT_MAX;

        arrows.insert(m);

    }

    cout << arrows.size();

}