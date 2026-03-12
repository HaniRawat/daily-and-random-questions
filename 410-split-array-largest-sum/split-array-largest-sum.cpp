class Solution {
public:

    bool canFit(vector<int>&nums, long long mid, int k) {
        int count = 1;
        int sum = 0;

        for(int num : nums) {
            if(sum + num > mid) {
                count++;
                sum = num;
            }
            else {
                sum += num;
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = 0;
        int maxi = 0;

        if(n < k)   return 0;

        for(int num : nums) {
            mini = max(mini, num);
            maxi += num;
        }

        int ans = 0;
        while(mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;

            if(canFit(nums, mid, k)) {
                ans = mid;
                maxi = mid - 1;
            } 
            else {
                mini = mid + 1;
            }
        }
        return ans;
    }
};