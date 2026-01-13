class Solution {
public:
    //Space Optimization
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        int MOD = 1e9 + 7;
        vector<int> prev(m+1, 0), curr(m+1, 0);

        prev[0] = curr[0] = 1; // base case

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = (prev[j-1] + prev[j]) % MOD; //either skip or match the characters
                }
                else curr[j] = prev[j] % MOD;   //skip the char
            }
            prev = curr;
        }

        return prev[m];
    }
};