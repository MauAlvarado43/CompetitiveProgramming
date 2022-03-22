#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m;
    cin >> n >> m;

    set<string> words;

    for(int i = 0; i < n + m; i++) {
        string s;
        cin >> s;
        words.insert(s);
    }

    int total = n + m - words.size();
    n += total % 2 == 1;

    if(n > m)
        cout << "YES";
    else
        cout << "NO";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}