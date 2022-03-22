#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void solve() {

    int a = 0;
    int b = 0;
    int c = 0;

    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++) {

        if(s[i] == 'A') 
            a++;
        else if(s[i] == 'B') 
            b++;
        else if(s[i] == 'C') 
            c++;
        
    }

    if(a + c == b)
        cout << "YES\n";
    else
        cout << "NO\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while(t--)
        solve();

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}