#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int solve(vector<int>& nums) {

    int l = 0;
    int r = nums.size() - 1;

    int ans = -1;

    while(l <= r) {

        int m = (l + r) / 2;

        if(nums[m] == m) {
            ans = m;
            r = m - 1;
        }
        else if(nums[m] < m)
            l = m + 1;
        else if(nums[m] > m)
            r = m - 1;

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