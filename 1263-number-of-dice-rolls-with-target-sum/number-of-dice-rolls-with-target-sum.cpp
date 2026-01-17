class Solution {
public:
    static const int MOD = 1e9 + 7;
    int solve(int n, int k, int target, vector<vector<int>> &dp) {
        if(n == 0)  return target == 0;
        if(dp[n][target] != -1) return dp[n][target];

        int count = 0;
        for(int face = 1; (face <= k && face <= target); face++) {
            count = (count + solve(n - 1, k, target - face, dp)) % MOD;
        }

        return dp[n][target] = count;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};