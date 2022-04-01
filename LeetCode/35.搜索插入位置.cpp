/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int binary_search(vector<int>& nums, int start, int end, int target) {
        int mid = (start + end) / 2;
        // base case
        if (nums[mid] == target) return mid;
        // insert if reached final digit but doesnt exist
        else if(start == end) {
            if (nums[mid] < target) {
                nums.insert(nums.begin() + start + 1, target);
                return start + 1;
            }
            nums.insert(nums.begin() + start, target);
            return start;
        }
        // search lower half
        else if (nums[mid] > target) return binary_search(nums, start, mid, target);
        // search upper half
        else return binary_search(nums, mid + 1, end, target); 
    }

    /**
     * @brief given a sorted array, find the index of target
     * 
     * @param nums sorted array
     * @param target value in array
     * @return int 
     */
    int searchInsert(vector<int>& nums, int target) {
        // binary search O(logn)
        return binary_search(nums, 0, nums.size() - 1, target);

    }
};
// @lc code=end

