class Solution {

    static bool comparator(vector<int>&nums1, vector<int>&nums2) {
        if(nums1[0] == nums2[0])    
            return nums1[1] > nums2[1]; // If widths are same then sort by height in descending order
            //why descending, cause
            // Input:
            // [ [5,4], [5,5] ]

            // Sorted:
            // [ [5,4], [5,5] ]

            //now if we run LIS, it will take 4 -> 5 as increasing and include it in the answer
            // which is incorrect, as the width is same so the height 4 cant nest height 5 doll, 
            // so its invalid therefore we sort it in descending manner

        return nums1[0] < nums2[0]; ///sort by width in ascending order
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {

        int n = env.size(), maxLength = 1;
        sort(env.begin(), env.end(), comparator);

        vector<int>LIS;

        LIS.push_back(env[0][1]);

        for(auto& currEnv : env) {
            if(LIS.back() < currEnv[1]) {
                LIS.push_back(currEnv[1]);
                maxLength++;
            }  
            else {
                int i = lower_bound(LIS.begin(), LIS.end(), currEnv[1]) - LIS.begin();

                if(i >= 0 && i < maxLength)
                    LIS[i] = currEnv[1];
            }
        }
        return maxLength;
    }
};