class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b = 0, a = 0, l = 0, o = 0, n = 0;

        for(char s : text) {
            if(s == 'b')    b++;
            if(s == 'a')    a++;
            if(s == 'l')    l++;
            if(s == 'o')    o++;
            if(s == 'n')    n++;
        }

        return min({b, a, l/2, o/2, n});
    }
};