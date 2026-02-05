class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, ele = nums[0];

        for(int i=1; i<nums.size(); i++) {
            if(ele == nums[i])
                count++;
            else
                count--;

            if(count <= 0){
                ele = nums[i];
                count = 1;
            }
        }

        return ele;
    }
};