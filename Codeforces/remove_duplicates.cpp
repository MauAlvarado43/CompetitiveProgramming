#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n;
    cin >> n;

    vector<int> _array(n);
    vector<int> numbers(100000, 0);
    vector<int> appearance;
    vector<int> appearance_indexes(100000, 0);

    for(int i = 0; i < n; i++) {
        
        cin >> _array[i];
        numbers[_array[i]]++;

        if(numbers[_array[i]] != 1) {

            appearance.erase(appearance.begin() + appearance_indexes[_array[i]]);
            appearance.push_back(_array[i]);

            for(int i = 0; i < appearance.size(); i++) 
                appearance_indexes[appearance[i]] = i;    

        }

        if(numbers[_array[i]] == 1) {
            appearance.push_back(_array[i]);
            appearance_indexes[_array[i]] = appearance.size() - 1;
        }

    }

    cout << appearance.size() << "\n";

    for(int x : appearance) 
        cout << x << " ";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}