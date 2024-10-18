#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

ll binpow(ll a, ll b, ll m) {

    a %= m;
    ll res = 1;

    while(b > 0) {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    
    return res;

}

vector<int> primesSieve(int n){

	vector<bool> isPrime(n + 1, true);
	vector<int> primes = {2};
	isPrime[0] = isPrime[1] = false;

	for(int i = 4; i <= n; i += 2) 
        isPrime[i] = false;

	for(int i = 3; i <= n; i += 2) 
		if(isPrime[i]) {
			primes.push_back(i);
			if((ll) i * i <= n)
				for(int j = i * i; j <= n; j += 2 * i)
					isPrime[j] = false;
		}

	return primes;

}

vector<bool> sieveEratosthenes(int n) {
    
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= n; i++)
        if(isPrime[i])
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = false;

    return isPrime;

}

bool isPrime(ll x) {
    
    for(ll d = 2; d * d <= x; d++)
        if(x % d == 0) 
            return false;
    
    return true;

}

bool checkComposite(ll n, ll a, ll d, ll s) {

    ll x = binpow(a, d, n);
    if(x == 1 || x == n - 1) return false;

    for(int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1) return false;
    }

    return true;

}

bool millerRabin(ll n) {

    if(n < 2) return false;

    ll r = 0;
    ll d = n - 1;
    
    while((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(n == a) return true;
        if(checkComposite(n, a, d, r)) return false;
    }

    return true;

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