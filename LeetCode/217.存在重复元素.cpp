/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> hash_table;
        for (int i = 0; i < nums.size(); i++) {
            if (hash_table.find(nums[i]) != hash_table.end()) return true;
            hash_table.insert({nums[i]});
        }
        return false;

    }

    // hashtable
};
// @lc code=end

