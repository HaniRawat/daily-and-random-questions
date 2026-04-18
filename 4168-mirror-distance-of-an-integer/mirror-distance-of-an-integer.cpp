class Solution {
public:
    int reverse(int num) {
        int res = 0;

        while(num) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
    int mirrorDistance(int n) {
        int reverseN = reverse(n);

        return abs(reverseN - n);
    }
};