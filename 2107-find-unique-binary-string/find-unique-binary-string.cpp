class Solution {
public:
    // vector<string>vec;

    // void solve(int n, string s) {
    //     if(n == 0) {
    //         vec.push_back(s);
    //         return;
    //     }

    //     solve(n-1, s + "0");
    //     solve(n-1, s + "1");
    // }
    string findDifferentBinaryString(vector<string>& nums) {
        //O((2^N) * N)

        // int n = nums[0].size();

        // map<string, int>mp;
        // for(auto x : nums)  mp[x]++;

        // solve(n, "");

        // for(auto x : vec)
        //     if(!mp.count(x))    return x;
        
        // return "";

        //cantor's diagonalization

        int n = nums.size();
        string ans = "";

        for(int i=0; i<n; i++) {
            ans += (nums[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
};