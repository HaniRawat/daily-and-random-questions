class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            // Calculate how many numbers are missing before the index 'mid'
            // Expected value at index mid is (mid + 1)
            int missingNumbersTillNow = arr[mid] - (mid + 1);

            if(missingNumbersTillNow < k)
                start = mid + 1;     // Not enough missing numbers yet, look to the Right
            else
                end = mid - 1;       // Too many (or exactly k) missing numbers, look to the Left
        }

        // Derivation:
        // The answer is 'k' more than the number of non-missing elements found so far.
        // At the end of the loop, 'start' is the number of elements in the array smaller than the kth missing number.
        // Formula: Result = k + start
        return k + start;
    }
};