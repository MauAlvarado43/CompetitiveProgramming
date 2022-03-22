#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    long long int sumHeroes = 0;
    long long int n;
    cin >> n;

    vector<long long int> heroes(n);

    for(long long int i = 0; i < n; i++) {
        cin >> heroes[i];
        sumHeroes += heroes[i];
    }

    sort(heroes.begin(), heroes.end());

    long long int m;
    cin >> m;

    for(int i = 0; i < m; i++) {

        long long int def, attk;
        cin >> def >> attk;

        long long j = lower_bound(heroes.begin(), heroes.end(), def) - heroes.begin();
        
        long long k = 0;

        if(j == n) k = n - 1;
        else if(j == 0) k = 0;
        else if(abs(heroes[j] - def) + abs(attk - sumHeroes + heroes[j]) > abs(def - heroes[j - 1]) + abs(attk + heroes[j - 1] - sumHeroes)) k = j - 1;
        else k = j;

        long long int coins = 0;

        if(def >= heroes[k]) coins = def - heroes[k];
        if(attk >= sumHeroes - heroes[k]) coins += attk + heroes[k] - sumHeroes;

        cout << coins << "\n";     

    }

    return 0;

}