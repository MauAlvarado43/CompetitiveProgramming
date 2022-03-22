#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

void solve(string origin, string destiny, stack<char> letters, string output, string sequence, int i, int j) {

    if(i == destiny.length()) {

        while(!letters.empty()) {
            output += letters.top();
            sequence += "o ";
            letters.pop();
        }
        
        if(output == destiny)
            cout << sequence.substr(0, sequence.length() - 1) + "\n";

        return;
    }

    if(i < destiny.length()) {
        letters.push(origin[i]);
        solve(origin, destiny, letters, output, sequence + "i ", i + 1, j);
        letters.pop();
    }

    if(!letters.empty() && destiny[j] == letters.top()) {
        char t = letters.top();
        letters.pop();
        solve(origin, destiny, letters, output + t, sequence + "o ", i, j + 1);
    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    string origin, destiny;

    while(cin >> origin >> destiny) {

        cout << "[\n";
        solve(origin, destiny, stack<char>(), "", "", 0, 0);
        cout << "]\n";

    }

    return 0;

}