/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int binary_search(long long int start, long long int end) {
        if(end - start >= 0) {
            long long int mid = (start + end) / 2;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == -1) return binary_search(start, mid);
            else return binary_search(mid + 1, end);
            
        }
        else return -1;
    }
    int guessNumber(int n) {
        return binary_search(1, n); 
    }

    // loop through all numbers O(n
    // binary search
};
// @lc code=end

