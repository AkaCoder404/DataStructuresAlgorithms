/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <unordered_set>
#include <unordered_map>
class Solution {
    // std::unordered_map<int, int> hashmap;
    std::unordered_map<int, int> hashmap;
public:
    int abs(int x) {
        if (x < 0) return -1 * x;
        return x;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         if (nums[i] == nums[j] && abs(i - j) <= k) return true;
        //     }
        // }
        // return false;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashmap.find(nums[i]);
            if ( it != hashmap.end()) {
                if (abs(i - hashmap[nums[i]]) <= k) return true;
                // hashmap[i] = i;
            }
            // hashmap.insert({nums[i], i});
            hashmap[nums[i]] = i;
        }
        return false;

    }

};
// @lc code=end

