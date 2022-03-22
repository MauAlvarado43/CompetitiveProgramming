class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> l(nums.size() + 1);
        vector<int> r(nums.size() + 1);
        vector<int> ans(nums.size());
        
        l[0] = 1;
        r[nums.size()] = 1;
        
        for(int i = 1; i < l.size(); i++)
            l[i] = l[i - 1] * nums[i - 1];
        
        for(int i = nums.size() - 1; i >= 0; i--)
            r[i] = r[i + 1] * nums[i];
        
        for(int i = 0; i < ans.size(); i++)
            ans[i] = l[i] * r[i + 1];
        
        return ans;
        
    }
};