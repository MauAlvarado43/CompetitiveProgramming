#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void solve(int n) {

    deque<int> s;
    for(int i = n; i > 0; i--) 
        s.push_back(i);

    cout << "Discarded cards:";

    if(n != 1)
        cout << " ";

    while(s.size() > 1) {

        cout << s.back();

        if(s.size() > 2)
            cout << ", ";

        s.pop_back();

        s.push_front(s.back());
        s.pop_back();

    }

    cout << "\nRemaining card: " << s.back() << "\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while(t) {
        solve(t);
        cin >> t;
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}