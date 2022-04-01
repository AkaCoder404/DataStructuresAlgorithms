/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroes = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                zeroes++;
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        while(zeroes--) nums.push_back(0);
    }
    // method1 vector erase all zeroes, and push_back at the end
    // method2 
};
// @lc code=end

