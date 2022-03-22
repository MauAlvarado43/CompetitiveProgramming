#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int solve(vector<int>& nums, int target) {
    
    int l = 0;
    int r = nums.size() - 1;
    int ans = INT_MAX;

    sort(nums.begin(), nums.end());

    while(l < r) {

        int x = nums[l] + nums[r];

        if(x > target) {
            r--;
            ans = min(x, ans);
        } 
        else 
            l++;

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