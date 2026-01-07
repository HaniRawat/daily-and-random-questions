class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //we have two possibilites, the max subarray sum is in (i) middle of the array -> simply apply the kadane's algo to find the max subarray sum
        // if the max subarray sum is in the circular array -> subtract the minimum sum array from total sum of the array

        // answer = max(sum returned by kadane , totalSum - minimum sum subarray)

        int maxSum = INT_MIN;
        int sum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);

            if(sum < 0) sum = 0;
        }

        int mini = 0;
        int miniSum = INT_MAX, total = 0;

        for(int i=0; i<n; i++) {
            total += nums[i];

            mini += nums[i];
            miniSum = min(miniSum, mini);

            if(mini > 0)    mini = 0;
        }

        // All elements are negative
        if(maxSum < 0) return maxSum;

        return max(maxSum, total - miniSum);
        
    }
};