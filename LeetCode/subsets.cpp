class Solution {
public:
    
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int i) {

    ans.push_back(temp);

    for(int j = i; j < nums.size(); j++) {
        temp.push_back(nums[j]);
        solve(ans, temp, nums, j + 1);
        temp.pop_back();
    }

}
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans = {};
        vector<int> temp = {};
        solve(ans, temp, nums, 0);
        
        return ans;
    }
    
};