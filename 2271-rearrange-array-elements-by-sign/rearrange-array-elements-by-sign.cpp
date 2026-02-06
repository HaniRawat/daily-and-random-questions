class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos, neg;

        for(int num : nums) {
            if(num > 0) pos.push_back(num);
            else    neg.push_back(num);
        }

        int n = pos.size();
        int i = 0;
        nums.clear();
        while(i < n) {
            nums.push_back(pos[i]);
            nums.push_back(neg[i]);

            i++;
        }

        return nums;
    }
};