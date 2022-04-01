/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int actual_sum = ((size) * (size + 1)) / 2;  // n(n-1)/2
        int sum = 0;
        for(int i = 0; i < size; i++) sum += nums[i];

        return actual_sum - sum;

    }
};
// @lc code=end

