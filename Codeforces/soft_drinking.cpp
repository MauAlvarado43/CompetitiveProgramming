#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    int k, ml, g, l, r;
    int x, y;

    cin >> n >> k >> ml >> l >> r >> g >> x >> y;

    int u = (k * ml) / x;
    int v = g / y;
    int w = l * r;

    cout << min(u / n, min(v / n, w / n));

    return 0;

}