#include <bits/stdc++.h>
#include <chrono>

#define ll long long int
#define PI 3.141592653589793238463 

using namespace std;

void solve(int tt) {

    double x, a, y = 0.0;
    scanf("%lf %lf", &x, &a);

    double total = x;

    for(int i = 1; i < tt; i++) {

        double z, d, m, s;
        scanf("%lf %lf d %lf ' %lf \"", &z, &d, &m, &s);

        total += z;
        a += PI - ((d + (m / 60) + (s / 3600)) * PI / 180);
        x += z * cos(a);
        y += z * sin(a);

    }

    if(sqrt(pow(x, 2) + pow(y, 2)) / total < 0.001)
        cout << "Acceptable\n";
    else
        cout << "Not acceptable\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int tt;
    scanf("%d", &tt);

    while(tt) {
        solve(tt);
        scanf("%d", &tt);
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}