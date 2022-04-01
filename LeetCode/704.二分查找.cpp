/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
public:
    int binary_search(long long int start, long long int end, vector<int>& nums, int target) {
        if (end - start > 0) { 
            long long int mid = (end + start) / 2;
            if (nums[mid] == target) return mid;
            else if (target < nums[mid]) return binary_search(start, mid, nums, target);
            else return binary_search(mid + 1, end, nums, target);

        }
        else return -1;
    }

    int search(vector<int>& nums, int target) {
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == target) return i;
        // }
        // return -1;
        return binary_search(0, nums.size(), nums, target);
    }
};
// @lc code=end

