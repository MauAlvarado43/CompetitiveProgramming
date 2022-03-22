#include <bits/stdc++.h> 

using namespace std;

long long int factorial(long long int n) {

    if(n == 2)
        return 1;

    return n * factorial(n - 1) % 1000000007;

}

void solve() {
     
    long long int n;
    cin >> n;

    cout << factorial(2 * n) << "\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    long long int n;
    cin >> n;

    while(n > 0) {
        solve();
        n--;
    }

    return 0;

}