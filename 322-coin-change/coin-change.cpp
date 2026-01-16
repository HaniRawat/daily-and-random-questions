class Solution {
public:

    int f(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
        
        if(index == 0) {
            if(amount % coins[0] == 0)
                return amount/coins[0];
            else
                return 1e9;
        }
        if(dp[index][amount] != -1)
            return dp[index][amount];

        int notTake = 0 + f(coins, amount, index - 1, dp);
        int take = 1e9;

        if(coins[index] <= amount)
            take = 1 + f(coins, amount - coins[index], index, dp);

        return dp[index][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0) return 0;
        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        // int ans = f(coins, amount, n-1, dp);
        
        // if(ans >= 1e9)
        //     return -1;
        // return ans;

        //tabulation - 2d dp

        // const int INF = 1e9;
        // vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        // for(int t = 0; t <= amount; t++) {
        //     if(t % coins[0] == 0)
        //         dp[0][t] = t / coins[0];
        // }

        // for(int i=1; i<n; i++) {
        //     for(int t = 0; t <= amount; t++) {
        //         //exclude
        //         int notTake = dp[i-1][t];

        //         int take = INF;
        //         if(coins[i] <= t)
        //             take = 1 + dp[i][t - coins[t]];

        //         dp[i][t] = min(take, notTake);
        //     }
        // }
        // int ans = dp[n-1][amount];
        // return (ans >= INF ? -1 : ans);

        //space optimized
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9;
        }

        for(int ind = 1; ind < n; ind++){
            for(int target=0; target<=amount; target++){
                int notTake = prev[target];

                int take = 1e9;
                if(coins[ind] <= target){
                    take = 1 + curr[target-coins[ind]];
                }

                curr[target] = min(notTake, take);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if (ans >= 1e9)
            return -1;

        return ans;
    }
};