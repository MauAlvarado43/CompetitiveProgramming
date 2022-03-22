#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

vector<int> solve(vector<int>& nums, int k) {
    
    unordered_map<int, int> m;
  
    int l = 0;
    int r = 0;

    for(r = 0; r < k; r++) {
        if(m.find(nums[r]) == m.end())
            m.insert({nums[r], 1});
        else
            m[nums[r]]++;
    }

    vector<int> ans = {m.size()};

    while(r < nums.size()) {
    
        if(m.find(nums[r]) == m.end())
            m.insert({nums[r], 1});
        else
            m[nums[r]]++;

        m[nums[l]]--;

        if(m[nums[l]] <= 0)
            m.erase(nums[l]);

        l++;
        r++;

        ans.push_back(m.size());    

    }

    return ans;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}