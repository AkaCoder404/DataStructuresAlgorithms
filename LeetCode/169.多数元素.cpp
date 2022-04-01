/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // start with index 0, add 1 if similar, minus 1 if different, if zero, switch
        // uses the fact that there will always be a majority element
        int count = 1;
        int element = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) element = nums[i]; 
            if (nums[i] == element) count++;
            else if (nums[i] != element) count--;
        }
        return element;
    }
};
// @lc code=end

