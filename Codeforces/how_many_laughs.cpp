#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    // auto start = chrono::high_resolution_clock::now();
    
    int n, x; cin >> n >> x;

    vector<int> numbers(n);

    for(int i = 0; i < n; i++) {

        cin >> numbers[i];

        if(numbers[i] == 1) {
            cout << x << "\n";
            return 0;
        }

    }

    sort(numbers.begin(), numbers.end());

    unordered_map<int, int> ans;

    for(int i = 0; i < n; i++) {

        int temp = numbers[i];
        int n = numbers[i];

        while(temp <= x) {

            if(!ans[temp]) ans[temp] = n;
            else if(n % ans[temp] == 0) break;

            temp += n;
            
        }

    }

    cout << ans.size() << "\n";

    // auto end = chrono::high_resolution_clock::now();
    // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time_taken *= 1e-9;
    // cout << time_taken << setprecision(9) << "\n";

    return 0;

}