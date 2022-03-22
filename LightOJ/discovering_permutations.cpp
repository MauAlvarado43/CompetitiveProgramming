#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void solve(string temp, vector<bool>& used, int letters, int limit, int& count) {

    if(count == limit)
        return;

    if(temp.size() == letters) {
        count++;
        cout << temp << "\n";
        return;
    }

    for(int i = 0; i < letters; i++) {
        if(!used[i]) {
            used[i] = true;
            temp += 'A' + i;
            solve(temp, used, letters, limit, count);
            used[i] = false;
            temp.pop_back();
        }
    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    int tt = 0;

    while(t--) {

        vector<bool> used(26, false);
        int count = 0;

        int n, k;
        cin >> n >> k;

        cout << "Case " << tt + 1 << ":\n"; 
        solve("", used, n, k, count);

        tt++;

    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}