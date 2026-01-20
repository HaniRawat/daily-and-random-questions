class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto& n : nums) {
            if(n & 1) {
                auto z = ((n + 1) & ~n) >> 1;
                ans.push_back(n & ~z);
            }
            else    ans.push_back(-1);
        }
        return ans;
    }
};