class Solution {
public:

    int f(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target == 0)   return 0;
        if(index < 0)   return -1e9;

        if (dp[index][target] != -1)
            return dp[index][target];

        // Not take
        int notTake = f(index - 1, target, nums, dp);

        // Take
        int take = -1e9;
        if (nums[index] <= target) {
            int res = f(index - 1, target - nums[index], nums, dp);
            if (res >= 0)
                take = 1 + res;
        }
        return dp[index][target] = max(take, notTake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        int ans = f(n - 1, target, nums, dp);
        return (ans < 0) ? -1 : ans;
    }
};