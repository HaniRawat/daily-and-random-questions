class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[51][51][51];

    long solve(int m, int n, int maxMove, int startRow, int startCol) {
        if(startRow >= m || startRow < 0 || startCol >= n || startCol < 0)
            return 1;

        if(maxMove <= 0)    return 0;

        if(dp[startRow][startCol][maxMove] != -1)   return dp[startRow][startCol][maxMove];

        long count = 0;
        count += solve(m, n, maxMove - 1, startRow - 1, startCol);
        count += solve(m, n, maxMove - 1, startRow, startCol + 1);
        count += solve(m, n, maxMove - 1, startRow + 1, startCol);
        count += solve(m, n, maxMove - 1, startRow, startCol - 1);

        return dp[startRow][startCol][maxMove] = count % MOD;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn) % MOD;
    }
};