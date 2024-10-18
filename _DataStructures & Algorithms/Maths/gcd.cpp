#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

ll gcd(ll a, ll b) {
    if(!a || !b) return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while(b);
    return a << shift;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Allow to find a * x + b * y = gcd(a, b)
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

// Know if a Linear Diophantine Equation (a * x + b * y = c) has solutions
// To iterate solutions, do the following:
// x + k * (b / g) ; y - k * (a / g)
// x - k * (b / g) ; y + k * (a / g)
bool findAnySolution(ll a, ll b, ll c, ll& x, ll& y, ll& g) {

    g = extendedGcd(abs(a), abs(b), x, y);

    if(c % g) return false;

    x *= c / g;
    y *= c / g;

    if(a < 0) x = -x;
    if(b < 0) y = -y;

    return true;

}

void shiftSolution(ll& x, ll& y, ll a, ll b, ll cnt) {
    x += cnt * b;
    y -= cnt * a;
}

// To find the number of solutions in a given interval
ll findAllSolutions(ll a, ll b, ll c, ll minx, ll maxx, ll miny, ll maxy) {

    ll x, y, g;

    if(!findAnySolution(a, b, c, x, y, g)) return 0;

    a /= g;
    b /= g;

    ll sign_a = a > 0 ? +1 : -1;
    ll sign_b = b > 0 ? +1 : -1;

    shiftSolution(x, y, a, b, (minx - x) / b);

    if(x < minx) shiftSolution(x, y, a, b, sign_b);
    if(x > maxx) return 0;

    int lx1 = x;

    shiftSolution(x, y, a, b, (maxx - x) / b);
    if(x > maxx) shiftSolution(x, y, a, b, -sign_b);

    int rx1 = x;

    shiftSolution(x, y, a, b, -(miny - y) / a);
    if(y < miny) shiftSolution(x, y, a, b, -sign_a);
    if(y > maxy) return 0;
    
    int lx2 = x;

    shiftSolution(x, y, a, b, -(maxy - y) / a);
    if(y > maxy) shiftSolution(x, y, a, b, sign_a);

    int rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);

    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if(lx > rx) return 0;

    return (rx - lx) / abs(b) + 1;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();
    
    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}