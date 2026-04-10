class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>>mp;
        int n = nums.size();

        for(int i=0; i<n; i++)  mp[nums[i]].push_back(i);

        int ans = INT_MAX;

        for(auto &it : mp) {
            auto &indices = it.second;

            if(indices.size() < 3)  continue;

            for(int i=0; i + 2 < indices.size(); i++) {
                int dist = 2 * (indices[i + 2] - indices[i]);
                ans = min(ans, dist);
            }
        }
        return ans == INT_MAX ? - 1 : ans;
    }
};