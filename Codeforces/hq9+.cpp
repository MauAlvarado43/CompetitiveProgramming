#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    string s;
    cin >> s;

    bool output = false;

    for(int i = 0; i < s.size(); i++) 
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
            output = true;

    if(output)
        cout << "YES";
    else
        cout << "NO";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}