/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <map>
#include <unordered_map>

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hashtable;
        std::vector<int> result(2, -1); // size 2 with initial value -1
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; 
            // returns iterator to element if found, else returns unordered_set:end
            auto it = hashtable.find(complement);
            if (it != hashtable.end()) { // takes O(1) time
                result[0] = hashtable[complement]; // it->second
                result[1] = i;
                return result;
            }
            hashtable.insert({nums[i], i}); // takes O(1) time
            // hashtable[nums[i]] = i;
        }
        return result;        
    }


    // hash map O(1) time complexity, O(n) space complexity
    vector<int> method3(vector<int> &nums, int target) {
        return nums;
    }
    // two pointers O(nlogn) time complexity, O(1) space complexity 
    vector<int> method2(vector<int> &nums, int target) {
        return nums;
    }
    // brute force method O(n^2) time complexity, O(1) space complexity
    vector<int> method1(vector<int> &nums, int target) {
        std::vector<int> result;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
// @lc code=end

