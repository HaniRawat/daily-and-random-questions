class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // vector<int>pos, neg;

        // for(int num : nums) {
        //     if(num > 0) pos.push_back(num);
        //     else    neg.push_back(num);
        // }

        // int n = pos.size();
        // int i = 0;
        // nums.clear();
        // while(i < n) {
        //     nums.push_back(pos[i]);
        //     nums.push_back(neg[i]);

        //     i++;
        // }

        // return nums;

        vector<int>ans(nums.size(), 0);
        int pos = 0, neg = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            }else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};