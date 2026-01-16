class Solution {
public:
    int f(int index, vector<int>&coins, vector<vector<int>>&dp, int amount) {
        if(index == 0)
            return (amount % coins[index] == 0);

        if(dp[index][amount] != -1) return dp[index][amount];

        int notTake = f(index - 1, coins, dp, amount);

        int take = 0;
        if(coins[index] <= amount) {
            take = f(index, coins, dp, amount - coins[index]);
        }

        return dp[index][amount] = take + notTake;

    }
    int change(int amount, vector<int>& coins) {
        int n  = coins.size();
        if (n == 0) return 0;

        // vector<vector<int>>dp(n + 1, vector<int>(amount + 1, -1));
        // int ans = f(n-1, coins, dp, amount);
        // return ans;

        //tabulation -> idk why it gives run-time error, when it should be in 32bit as guaranteed by leetcode
        // vector<vector<long long>>dp(n+1, vector<long long>(amount + 1, 0));

        // for(int a = 0; a <= amount; a++) {
        //     if(a % coins[0] == 0)
        //         dp[0][a] = 1;
        // }

        // for(int index=1; index<n; index++) {
        //     for(int target = 0; target <= amount; target++) {
        //         long long notTake = dp[index - 1][target];

        //         long long take = 0;
        //         if(coins[index] <= target) {
        //             take = dp[index][target - coins[index]];
        //         }

        //     dp[index][target] = take + notTake;
        //     }
        // }
        // return (int)dp[n-1][amount];

        //1-D dp
        vector<unsigned int>dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];

    }
};