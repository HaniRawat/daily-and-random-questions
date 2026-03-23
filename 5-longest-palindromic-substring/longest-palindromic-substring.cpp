class Solution {
public:

    string solve(int start, int end, string s) {
        while(start >= 0 && end < s.length() && s[start] == s[end]) {
            start--, end++;
        }
        return s.substr(start + 1, end - start - 1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1)  return s;

        string maxStr = s.substr(0, 1);
        for(int i=0; i<n; i++) {
            string oddLengthString = solve(i, i, s);
            string evenLengthString = solve(i, i+1, s);

            if(oddLengthString.length() > maxStr.length())  maxStr = oddLengthString;
            if(evenLengthString.length() > maxStr.length())  maxStr = evenLengthString;
        }

        return maxStr;
    }
};