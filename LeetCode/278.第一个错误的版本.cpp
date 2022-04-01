/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int binary_search(long long int start, long long int end) {
      
        long long int mid = (start + end) / 2;
        if (end - start >= 0) {
              // if bad, check before and after 
            if (isBadVersion(mid)) {
                // if before it is not bad, then it is first bad, else there is bad before it
                if (!isBadVersion(mid - 1)) return mid;
                return binary_search(start, mid);
            }
        // if it is not bad, there must be bad after
        return binary_search(mid + 1, end);
        }

        return -1;
      
    }
    int firstBadVersion(int n) {
        // for(int i = 1; i <= n; i++) {
        //     if(isBadVersion(i)) return i;
        // }
        // return n; 
        return binary_search(1, n);
    }

    // method 1 - O(n) loop until isBadVersion is true, TLE
    // method 2 - Binary search between 1 and n, log(n), Runtime Error because huge ints -> use long long int

};
// @lc code=end

