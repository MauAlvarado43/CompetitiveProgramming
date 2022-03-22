#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    vector<int> answer;
    deque<pair<int, int>> ans;

    for(int i = 0; i < nums.size(); i++) {

        while(!ans.empty() && ans.back().first < nums[i])
            ans.pop_back();

        ans.push_back(make_pair(nums[i], i));

        if(i - ans.front().second >= k)
            ans.pop_front();

        if(i >= k - 1)
            answer.push_back(ans.front().first);

    }

    return answer;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> tt = {1,3,-1,-3,5,3,6,7};

    vector<int> ans = maxSlidingWindow(tt, 3);

    for(int x : ans) cout << x << " ";

    return 0;

}