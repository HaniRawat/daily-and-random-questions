class Solution {
public:
    int f(vector<int> nums, int n, int ind, int prev_ind, vector<vector<int>>&dp) {
        if(ind == n)
            return 0;
        if(dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];
        
        int notTake = 0 + f(nums, n, ind + 1, prev_ind, dp);
        int take = 0;

        if(prev_ind == -1 || nums[ind] > nums[prev_ind])
            take = 1 + f(nums, n, ind + 1, ind, dp);

        return dp[ind][prev_ind + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n, vector<int>(n+1, -1));
        // return f(nums, n, 0, -1, dp);

        //[Tabulation]
        // vector<int>dp(n, 1);
        // int ans = 1;

        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<i; j++) {
        //         if(nums[i] > nums[j]){
        //             dp[i] = max(dp[i], dp[j] + 1);
        //             ans = max(ans, dp[i]);
        //         }
        //     }
        // }
        // return ans;

        //Binary Search
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = 1;

        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]), len++;
            }else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }

};