class Solution {
public:
    int findComplement(int num) {

        if(num == 0)    return 1;

        int temp = num;
        int mask = 0;

        while(temp) {
            mask = (mask << 1) | 1;
            temp >>=  1;
        }

        return num ^ mask;
    }
};