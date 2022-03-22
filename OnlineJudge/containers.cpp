#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

int solve(string containers) {

    vector<stack<char>> stacks;

    for(int i = 0; i < containers.size(); i++) {

        if(stacks.empty()) {
            stacks.push_back(stack<char>());
            stacks[0].push(containers[i]);
        } 
        else {

            bool pushed = false;

            for(int j = 0; j < stacks.size(); j++) {

                if(stacks[j].top() >= containers[i]) {
                    pushed = true;
                    stacks[j].push(containers[i]);
                    break;
                }

            }

            if(!pushed) {
                stacks.push_back(stack<char>());
                stacks.back().push(containers[i]);
            }

        }

    }

    return stacks.size();

}

int main() {

    int tt = 1;

    while(true) {

        string s;
        cin >> s;

        if(s == "end") break;

        cout << "Case " << tt++ << ": " << solve(s) << "\n";

    }

    return 0;

}