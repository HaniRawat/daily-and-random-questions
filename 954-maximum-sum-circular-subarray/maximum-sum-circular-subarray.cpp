class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //we have two possibilites, the max subarray sum is in (i) middle of the array -> simply apply the kadane's algo to find the max subarray sum
        // if the max subarray sum is in the circular array -> subtract the minimum sum array from total sum of the array

        // answer = max(sum returned by kadane , totalSum - minimum sum subarray)

        int sum = INT_MIN;
        int n = nums.size();
        int temp = 0;

        for(int i=0; i<n; i++){
            temp += nums[i];
            sum = max(sum,temp);

            if(temp<0)
                temp = 0;
        }

        int total = nums[0];
        int mini = nums[0];

        for(int i = 1; i<n; i++){
            total += nums[i];
            nums[i] = nums[i] + min(0,nums[i-1]);
            mini = min(mini, nums[i]);
        }

        if(total != mini){
            sum = max(sum, total - mini);
        }
        return sum;
        
    }
};