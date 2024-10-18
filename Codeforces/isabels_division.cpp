#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    string s;
    cin >> s;

    int n = stoi(s);
    int count = 0;

    for(int i = 0; i < s.length(); i++) {
        int x = s[i] - '0';
        if(x != 0 && n % x == 0)
            count++;
    }

    cout << count << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}