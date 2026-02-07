class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0;
        int count = 0;

        for(char c : s) {
            if(c == 'b')
                count++;
            else if(count != 0) {
                //found an 'a' after 'b's.
                //we need to delete one character to resolve this "ba" pair.
                res++;
                count--;
            }
        }
        return res;

    }
};