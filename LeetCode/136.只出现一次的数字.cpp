/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <unordered_set>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int size = nums.size();
        // std::unordered_set<int> hashmap;
        // for(int i = 0; i < size; i++) {
        //     // if found, remove, skip to nex
        //     if (hashmap.find(nums[i]) != hashmap.end()) {
        //         hashmap.erase(nums[i]);
        //         continue;
        //     }
        //     // doesn't exist, add
        //     hashmap.insert(nums[i]);
        // }
        // return *hashmap.begin();

        // since pairs of 2, use XOR to remove all bits that are pairs of two
        int bit = 0;
        for (int i = 0; i < nums.size(); i++) {
            bit = bit ^ nums[i];
        }
        return bit;

 

    }

    // method 1 hashmap, store into hashmap, if already exists, remove, runtime slow, space complexity bad
    // method 2 bit manipulation, faster, saves more space
};
// @lc code=end

