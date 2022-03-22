#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    string s;
    cin >> s;

    vector<char> answer;

    for(int  i = 0; i < s.size(); i++) {
        
        if(answer.empty()) {
            answer.push_back(s[i]);
        }
        else {
            if(answer.back() == s[i]) {
                answer.pop_back();
            }
            else {
                answer.push_back(s[i]);
            }
        }

    }

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}