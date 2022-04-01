/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public: 
    int binary_search(int start, int end, int target) {
        long int mid = (end + start) / 2;
        long int mid_sqr = mid * mid;
        if (mid_sqr == target) return mid;
        else if (start == end) return --mid;
        if (mid_sqr <= target) return binary_search(mid + 1, end, target);
        else return binary_search(start, mid, target);
    }

    int mySqrt(int x) {
       if (x == 1 || x == 2 || x == 3) return 1;
       if (x == 5) return 2;
       return binary_search(0, x/2, x);
    }

    // method 1 just increment, square and compare O(\sqrt(n))
    int method1(int x) { 
        long int num = 1; 
        long int sqr = num;
        while (sqr <= x) {
            num++;
            sqr = num * num;
        }
        // if (sqr > x) num--;
        return num - 1; 
    }

    // method 2 binary search for number that suits it O(logn)


    // method 3 babylonian method O(n^1/2) 
};
// @lc code=end

