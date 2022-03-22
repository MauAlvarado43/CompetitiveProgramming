#include <bits/stdc++.h> 

using namespace std;

long long int solve(long long int n) {

    long long int rigth = n % 10;
    long long int left = 0;
    long long int cN = n;
    long long int count = 0;

    if(n < 10) return n; 

    while(cN > 0) {
        left = cN % 10;
        cN /= 10;
    }

    count = (n / 10) + 9;

    if(left > rigth)
        count--;

    return count;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    long long int l, r;
   
    cin >> l >> r;
    cout << solve(r) - solve(l - 1);

    return 0;

}