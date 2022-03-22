#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void getFactorization(vector<int> factors, int n, vector<int> factorsTemp, set<vector<int>>& factorizations) {

    if(n == 1) {

        sort(factorsTemp.begin(), factorsTemp.end());

        if(factors.size() != 0)
            factorizations.insert(factorsTemp);

        return;

    }

    for(int i = 0; i < factors.size(); i++) {

        if(n % factors[i] == 0) {
            factorsTemp.push_back(factors[i]);
            getFactorization(factors, n / factors[i], factorsTemp, factorizations);
            factorsTemp.pop_back();
        }

    }

}

int main() {

    //ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    while(true) {

        int n;
        cin >> n;

        if(n == 0) break;

        vector<int> factors;

        for(int i = 2; i <= n / 2; i++) {
            
            if(n % i == 0) 
                factors.push_back(i);
            
        }

        set<vector<int>> factorizations;

        getFactorization(factors, n, vector<int>(), factorizations);

        cout << factorizations.size() << endl;

        for(auto it = factorizations.begin(); it != factorizations.end(); it++) {

            for(int i = 0; i < it -> size(); i++) {

                cout << it -> at(i);

                if(i != it -> size() - 1) 
                    cout << " ";

            }

            cout << "\n";

        }

    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}