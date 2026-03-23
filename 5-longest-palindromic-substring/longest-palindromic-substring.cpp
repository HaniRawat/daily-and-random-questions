class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        
        auto expandFromCenter = [&] (int left, int right){
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            return s.substr(left+1, right-left-1);
        };

        string maxStr = s.substr(0,1);

        for(int i=0; i<s.length()-1; i++){
            string odd = expandFromCenter(i, i);
            string even = expandFromCenter(i, i+1);

            if(odd.length() > maxStr.length())  maxStr = odd;
            if(even.length() > maxStr.length())  maxStr = even;
        }
        return maxStr;
    }
};