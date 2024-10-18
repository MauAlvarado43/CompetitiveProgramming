#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

ll extendedGcd(ll a, ll b, ll& x, ll& y) {

    x = 1; y = 0;
    ll x1 = 0, y1 = 1, a1 = a, b1 = b;

    while(b1) {
        ll q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }

    return a1;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    ll a, b, c, x, y, g, l;
    cin >> a >> b >> c;

    g = extendedGcd(a, b, x, y);

    x *= c / g;
    y *= c / g;

    ll dx = (b / g);
    ll dy = (a / g);

    if(c % g == 0) {

        if(x < 0 && y > 0) {

            ll n = abs(x) / dx;

            for(int i = 0; i < n + 2; i++) {
                x += dx;
                y -= dy;

                if(x >= 0 && y >= 0) {
                    cout << "Yes" << "\n";
                    return 0;
                }

                if(y < 0) break;

            }

            cout << "No" << "\n";

        }
        else if(x > 0 && y < 0) {

            ll n = abs(x) / dx;

            for(int i = 0; i < n + 2; i++) {
                x -= dx;
                y += dy;

                if(x >= 0 && y >= 0) {
                    cout << "Yes" << "\n";
                    return 0;
                }

                if(x < 0) break;

            }

            cout << "No" << "\n";
            
        }
        else if(x >= 0 && y >= 0) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }

    }
    else {
        cout << "No" << "\n";
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}