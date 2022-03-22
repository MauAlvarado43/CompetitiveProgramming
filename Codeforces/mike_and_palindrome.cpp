#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    string s;
    cin >> s;

    int count = 0;

    for(int i = 0; i < s.length() / 2; i++) {

        if(s[i] != s[s.length() - i - 1]) {
            count++;
        }

        if(count > 1) 
            break;

    }

    if(count == 1 || (count == 0 && s.length() % 2 == 1)) 
        cout << "YES" << "\n";
    else 
        cout << "NO" << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}