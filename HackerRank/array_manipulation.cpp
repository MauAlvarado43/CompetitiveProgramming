#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    long long int n, m;
    cin >> n >> m;

    vector<long long int> array(n, 0);

    for(long long int i = 0; i < m; i++) {
        
        long long int a, b, k;
        cin >> a >> b >> k;

        array[a - 1] += k;
        array[b] -= k;

    }

    long long int maxSum = 0;
    long long int carry = 0;

    for(long long int i = 0; i < n; i++) {
        carry += array[i];
        maxSum = max(maxSum, carry);
    }

    cout << maxSum << "\n";

    return 0;

}