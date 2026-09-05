class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int ansIndex = 0;
        int globalMax = INT_MIN;
        int ansMax = INT_MIN;

        for(int i=0; i<n; i++) {
            globalMax = max(nums[i], globalMax);

            if(i == ansIndex) 
                ansMax = max(ansMax, nums[i]);

            if(nums[i] < ansMax - k) {
                ansIndex = i + 1;
                ansMax = globalMax;
            }
        }

        return ansIndex < n ? ansIndex : -1;
    }
};