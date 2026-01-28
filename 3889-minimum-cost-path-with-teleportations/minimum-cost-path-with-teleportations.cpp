class Solution {
private:
    int m;
    int n;

public:
    void normalMoveUpdate(vector<vector<int>>& dp, const vector<vector<int>>& grid){
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(i>0) dp[i][j] = min(dp[i][j], grid[i][j] + dp[i-1][j]);
                if(j>0) dp[i][j] = min(dp[i][j], grid[i][j] + dp[i][j-1]);
            }
        }
    }

    // teleMap: sorted by (value asc, i asc, j asc)
    void teleportUpdate(vector<vector<int>>& dp, const vector<tuple<int,int,int>>& teleMap){
        const int ts = (int)teleMap.size();

        // 1) Equal-value group minima (forward scan)
        // if the teleport rule is < then we don't need to do this!
        int currVal = -1;
        int groupMin = INT_MAX;
        for(int idx=0; idx<ts; ++idx){
            auto [v, r, c] = teleMap[idx];
            if(v != currVal){
                currVal = v;
                groupMin = dp[r][c];
            } else {
                groupMin = min(groupMin, dp[r][c]);
                dp[r][c] = min(dp[r][c], groupMin);
            }
        }

        // 2) Suffix minimum over values ≥ current (backward scan)
        auto [v_last, r_last, c_last] = teleMap.back();
        int suffixMin = dp[r_last][c_last];
        for(int idx=ts-2; idx>=0; --idx){
            auto [v2, r, c] = teleMap[idx];
            int cur = dp[r][c];
            if(cur < suffixMin) {
                suffixMin = cur;
            } else {
                dp[r][c] = suffixMin;
            }
        }
    }

    int minCost(vector<vector<int>>& grid, int k) {
        m = (int)grid.size();
        n = (int)grid[0].size();

        // 1) Build and sort teleMap
        vector<tuple<int,int,int>> teleMap;
        teleMap.reserve((size_t)m * n);
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                teleMap.emplace_back(grid[i][j], i, j);
        sort(teleMap.begin(), teleMap.end());

        // 2) DP init
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;

        // 3) Iterate: normal relax then (optional) teleport relax
        for(int sk=k; sk>=0; --sk){
            normalMoveUpdate(dp, grid);
            if(sk > 0) teleportUpdate(dp, teleMap);
        }
        return dp[m-1][n-1];
    }
};