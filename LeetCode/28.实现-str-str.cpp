/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        // brute force or naive method O(m(n-m+1))
        int j = 0;  // track needle
        int haystack_length = haystack.length();
        int needle_length = needle.length();

        if (needle_length > haystack_length) return -1;  
        if (needle_length == 0) return 0;

        for(int i = 0; i < haystack_length; i++) {
            if (haystack[i] == needle[j]) {
                j++;
            }
            else {
                i -= j;
                j = 0;
            }
            if (j == needle.length()) return i - j + 1;     
        }

        return -1;
    }
    // method1 brute force method O(m(n-m+1))
    int 
    // method2 KMP pattern matching algorith
        
};
// @lc code=end

