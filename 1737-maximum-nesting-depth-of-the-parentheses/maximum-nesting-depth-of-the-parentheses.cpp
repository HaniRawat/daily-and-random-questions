class Solution {
public:
    int maxDepth(string s) {
        int depth = INT_MIN;
        int freq = 0;

        for(char c : s) {
            if(c == '(')    freq++;
            else if(c == ')')   freq--;

            depth = max(depth, freq);
        }
        return depth;
    }
};