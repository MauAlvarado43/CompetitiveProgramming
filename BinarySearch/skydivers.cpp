#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

bool isValid(vector<int>& nums, int m, int k) {

    int queue = 0;

    for(int i = 0; i < nums.size(); i++) {

        queue += nums[i];

        if(queue > m) {
            k--;
            queue = nums[i];
        }
        else if(queue == m) {
            k--;
            queue = 0;
        }

    }

    if(!k && queue || k < 0)
        return false;
    
    return true;

}


int solve(vector<int>& nums, int k) {

    int l = *max_element(nums.begin(), nums.end());
    int r = accumulate(nums.begin(), nums.end(), 0);

    int ans = 0;

    while(l <= r) {

        int m = (l + r) / 2;

        if(isValid(nums, m, k)) {
            r = m - 1;
            ans = m;
        }
        else {
            l = m + 1;
        }

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