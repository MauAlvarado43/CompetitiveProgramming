#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

void solve(int n) {

    bool stop = false;

    while(true) {

        stack<int> coaches;

        for(int i = 0, j = 1; i < n; i++) {

            int aux;
            cin >> aux;

            if(aux == 0) {
                stop = true;
                break;
            }

            while((coaches.empty() || coaches.top() != aux) && j <= n) {
                coaches.push(j);
                j++;
            }

            if(coaches.top() == aux)
                coaches.pop();

        }

        if(stop)
            break;

        if(coaches.size() == 0)
            cout << "Yes\n";
        else
            cout << "No\n";

    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int tt;
    cin >> tt;

    while(tt) {
        solve(tt);
        cin >> tt;
        cout << "\n";
    }

    return 0;

}