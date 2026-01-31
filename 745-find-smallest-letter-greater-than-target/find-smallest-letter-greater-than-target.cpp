class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];

        for(auto &c : letters) {
            if(c > target) {
                ans = c;
                break;
            }
        }
        return ans;
    }
};