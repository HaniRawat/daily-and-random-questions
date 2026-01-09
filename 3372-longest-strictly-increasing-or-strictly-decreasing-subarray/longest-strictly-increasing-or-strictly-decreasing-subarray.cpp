class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int descCnt = 1;
        int ascCnt = 1;
        int maxCnt = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                ascCnt++;
                descCnt = 1;      // reset
            } 
            else if (nums[i] < nums[i - 1]) {
                descCnt++;
                ascCnt = 1;      // reset
            } 
            else {
                ascCnt = descCnt = 1; // equal case
            }

            maxCnt = max(maxCnt, max(ascCnt, descCnt));
        }
        return maxCnt;
    }
};