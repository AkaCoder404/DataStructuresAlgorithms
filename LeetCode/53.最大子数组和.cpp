/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int prefix = nums[0]; // sum of integers before it
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // if (nums[i] > prefix && prefix < 0) {
            if (prefix < 0) {
                sum = nums[i];
                prefix = sum;
            }
            else {
                sum += nums[i];
                prefix = sum;
            }
            if (sum > max) max = sum;

            // simpler method because I am stupid
            // if (sum < 0) sum = 0;
            // sum += nums[i];
            // if (sum > max) max = sum;
        }
        return max;

    }
    
    // brute force all possible substrings O(n^3) - time limit exceeded
    int method1(vector<int>& nums) {
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            for(int j = i; j < nums.size(); j++) {
                int sum = nums[i];
                for(int k = i + 1; k <= j; k++) {
                    sum += nums[k];
                }
                if (sum > max) max = sum;
            }
        }   
        return max;
    }
    
    // incremental strategy O(n^2), we already know sum of previous, just add next, and compare with max
    // time limit exceeded on 203/209 case
    int method2(vector<int>& nums) {
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j]; // calculate the total sum of substring
                // whenever total sum of substring > max, save it
                if (max < sum) max = sum;
            }
        }
        return max;
    }




    // sliding window, increment left pointer if prefix is negative
    // time complexity O(n)


    // divide and conquer method O(nlogn) 
    int method3(vector<int>& nums) {
        return 0;
    }
};
// @lc code=end

