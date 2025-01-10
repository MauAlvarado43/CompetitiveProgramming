#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;

    while(t--) {

      ll n, k;
      cin >> n >> k;

      if(n < k) {
        cout << n << "\n";
      }
      else if(n == k) {
        cout << "1\n";
      }
      else if (k == 1) {
        cout << n << "\n";
      }
      else {
        
        vector<ll> v;
        int i = 1;
        while(true) {
          ll temp = binpow(k, i);
          if(temp > n) break;
          v.push_back(temp);
          i++;
        }

        int ans = 0;
        for(int j = v.size() - 1; j >= 0; j--) {
          while(n >= v[j]) {
            n -= v[j];
            ans++;
          }
        }

        cout << ans + n << "\n";

      }

    }

    return 0;

}