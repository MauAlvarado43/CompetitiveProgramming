#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

// F_0 = 0, F_1 = 1 -> F_n = F_n-1 + F_n-2
// Ex: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

// Properties:
// Cassini's identity: (F_n-1)(F_n+1)-(F_n)^2 = (-1)^n
// Addition rule: F_n+k = (F_k)(F_n+1) + (F_k-1)(F_n)
// Zeckendorf's theorem: Any natural number can be expressed as a sum of Fibonacci numbers
// mcd: mcd(F_m, F_n) = F_mcd(m, n)
// If F_m is multiple oF_ F_n, then m is multiple oF n
// The Fibonacci sequence modulo p is periodic
// sum(F_i, n) = Fn - 1

// Binet's Formula: F_n = (1 + sqrt(5))^n - (1 - sqrt(5))^n / (2^n * sqrt(5))
// Matrix Form:
// (F_n F_n+1) = (F_0 F_1) * P^n, where P = [[0 1], [1 1]]

// Fast Doubling Method:
// F_2k = F_k(2F_k+1 - F_k)
// F_2k+1 = (F_k+1)^2 + (F_k)^2

// Returns F_n and F_n+1
pair<int, int> fib(int n) {
    if(n == 0) return {0, 1};
    auto p = fib(n >> 1);

    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;

    if(n & 1) return {d, c + d};
    else return {c, d};
}

int fibonacci(int n) {

    vector<int> f(n + 1, 0);
    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]);

    return f[n];

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