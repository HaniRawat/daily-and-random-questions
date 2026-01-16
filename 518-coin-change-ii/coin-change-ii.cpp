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

        vector<vector<int>>dp(n + 1, vector<int>(amount + 1, -1));
        int ans = f(n-1, coins, dp, amount);
        return ans;
    }
};