class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int>ch(26);
        for(int i=0; i<26; i++) ch[i] = i + 1;

        int cnt = 0;
        for(char &i : chars) {
            ch[i - 'a'] = vals[cnt++];
        }

        int maxi = 0;
        int cur = 0;

        for(char &i : s) {
            cur += ch[i - 'a'];
            maxi = max(maxi, cur);

            if(cur < 0)
                cur = 0;
        }
        return maxi;
    }
};