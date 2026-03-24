class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), MOD = 12345;
        int total = n * m;

        vector<int> left(total);
        left[0] = 1;

        for(int pos = 1; pos < total; pos++) {
            int prev = pos - 1;
            int i = prev / m;
            int j = prev % m;
            left[pos] = (1LL * left[prev] * grid[i][j]) % MOD;
        }

        vector<vector<int>> dp(n, vector<int>(m));
        int right = 1;

        for(int pos = total - 1; pos >= 0; pos--) {
            int i = pos / m;
            int j = pos % m;

            dp[i][j] = (1LL * left[pos] * right) % MOD;
            right = (1LL * right * grid[i][j]) % MOD;
        }

        return dp;
    }
};