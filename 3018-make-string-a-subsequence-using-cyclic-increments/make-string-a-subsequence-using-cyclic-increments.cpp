class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int i = 0, j = 0;

        while(i < n && j < m) {
            char nextChar = (str1[i] == 'z') ? 'a' : str1[i] + 1;

            if(str1[i] == str2[j] || nextChar == str2[j])
                j++;
            i++;
        }
        return j == m;
    }
};