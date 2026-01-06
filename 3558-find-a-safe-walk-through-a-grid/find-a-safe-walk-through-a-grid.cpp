class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};

        queue<pair<pair<int,int>, int>>q;

        vector<vector<int>>dp(m, vector<int>(n, -1));
        q.push({{0,0}, health - grid[0][0]});

        dp[0][0] = health - grid[0][0];

        while(!q.empty()) {
            auto [pos, currHealth] = q.front();
            q.pop();

            int x = pos.first;
            int y = pos.second;

            if(x == m-1 && y == n-1 && currHealth > 0)  return true;

            for(auto [dx, dy] : dir) {
                int newX = x + dx;
                int newY = y + dy;

                if(newX >= 0 && newX < m && newY >= 0 && newY < n) {
                    int newHealth = currHealth - grid[newX][newY];

                    if(newHealth > 0 && newHealth > dp[newX][newY]) {
                        dp[newX][newY] = newHealth;
                        q.push({{newX, newY}, newHealth});
                    }
                }
            }
        }
        return false;
    }
};