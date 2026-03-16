class Solution {
public:

    int noOfOnes(vector<int>&row, int n) {
        if(n == 1)  return row[0] == 1;

        int low = 0;
        int high = n - 1;

        sort(row.begin(), row.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(row[mid] == 1)   
                high = mid - 1;
            else
                low = mid + 1;
        }
        return (n - 1) - low + 1;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        // O(M * N)
        // vector<int>ans;
        // int maxi = INT_MIN;
        // for(int i=0; i<mat.size(); i++) {
        //     int count = 0;

        //     for(int j=0; j<mat[0].size(); j++) {
        //         if(mat[i][j] == 1)
        //             count++;
        //     }

        //     if(count > maxi) {
        //         maxi = count;
        //         ans = {i, maxi};
        //     }
        // }
        // return ans;

        // O(M * log N)
        int maxi = 0;
        int indexOfMaxRow = 0;
        int m = mat.size();
        int n = mat[0].size();

        for(int i=0; i<m; i++) {
            int oneInThisRow = noOfOnes(mat[i], n);

            if(oneInThisRow > maxi) {
                maxi = oneInThisRow;
                indexOfMaxRow = i;
            }
        }
        return {indexOfMaxRow, maxi};

    }
};