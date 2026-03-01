class Solution {
public:

// Key Insight:
// When you add several deci‑binary numbers, each column (units, tens, hundreds, …) is simply the sum of the digits from each number in that column. Because each digit is at most 1, the total in a column equals the count of deci‑binary numbers that have a 1 in that column.

// That means: to get a digit d in the final number, you need at least d deci‑binary numbers that put a 1 in that column. And this has to happen for every column simultaneously.

// So the minimum number we need is the largest digit in n. Because we must have at least that many numbers to satisfy that column, and we can always build exactly that many numbers to cover all columns.
    int minPartitions(string n) {
       int ans = 0;
       for(char &c : n) ans = max(ans, c - '0');
        return ans;
    }
};