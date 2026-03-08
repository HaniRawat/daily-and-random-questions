class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //our answer lies between 1 and max(piles), 
        //for a mid value k, total hours needed = ceil(pile / k) for each pile
        //if total hours <= h, update answer and search for minimum answer

        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while(l <= r) {
            int mid = l + (r-l)/2;
            long long hours = 0;

            for(int p : piles)
                hours += (p + mid - 1) / mid;

            if(hours <= h) {
                ans = mid;
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return ans;
    }
};