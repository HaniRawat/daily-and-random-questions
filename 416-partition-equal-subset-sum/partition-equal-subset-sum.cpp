class Solution {
public:
    bool solve(vector<int>&nums, int target, int index, vector<vector<int>>&dp) {
        if(target == 0)
            return true;

        if(index == 0)
            return nums[0] == target;

        if(dp[index][target] != -1)
            return dp[index][target];


        bool notTake = solve(nums, target, index - 1, dp);
        bool take = false;
        if(nums[index] <= target)
            take = solve(nums, target - nums[index],index - 1, dp);

        return dp[index][target] = notTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        for(int num : nums) total += num;

        if(total & 1)   return false;
        int target = total / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(nums, target, n-1, dp);
    }
};