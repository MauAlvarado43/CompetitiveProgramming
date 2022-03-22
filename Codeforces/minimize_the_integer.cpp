#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void solve() {


    string s;
    cin >> s;

    vector<int> odd;
    vector<int> even;

    for(int i = 0; i < s.length(); i++) {
        
        int t = s[i] - '0';
        
        if(t % 2 == 0)
            even.push_back(t);
        else 
            odd.push_back(t);

    }

    int i = 0;
    int j = 0;

    while(i < odd.size() || j < even.size()) {
        
        if(i < odd.size() && j < even.size()) {

            if(odd[i] < even[j]) {
                cout << odd[i];
                i++;
            } else {
                cout << even[j];
                j++;
            }

        }
        else if(i < odd.size()) {
            cout << odd[i];
            i++;
        }
        else if(j < even.size()) {
            cout << even[j];
            j++;
        } 

    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while(t--) {
        solve();
        cout << "\n";
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}