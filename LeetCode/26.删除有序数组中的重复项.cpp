/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // method 1
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] != nums[j]) {
                    i = j - 1;
                    nums[++count] = nums[j];
                    break;
                }
            }            
        }
        return ++count;
        // return count - 2;
        // shorter version of above bc i am stupid
        // int count = 0;
        // for (int i = 0 ;  i < nums.size(); i++) {
        //     if (nums[i] > nums[count]) nums[++count] = nums[i]; 
        // }
        // return ++count;
    }
};
// @lc code=end

