int solve(vector<int>& nums) {
    
    int num = 0;
    int sum = 0;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if(sum < 0) {
            num += -sum;
            sum = 0;
        }
    }

    return num + 1;

}