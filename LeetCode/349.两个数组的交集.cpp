/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <algorithm>
#include <unordered_set>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> results;

        // for(int i = 0; i < nums1.size(); i++) {
        //     for(int j = 0; j < nums2.size(); j++) {
        //         if (nums1[i] == nums2[j]) {
        //             int k;
        //             for(k = 0; k < results.size(); k++) {
        //                 if (results[k] == nums1[i]) break;
        //             }
        //             if (k == results.size()) {
        //                 results.push_back(nums1[i]);
        //                 break;
        //             }
        //         }
        //     }
        // }
        // std::sort(nums1.begin(), nums1.end());
        // std::sort(nums2.begin(), nums2.end());

        // for(int i = 0; i < nums1.size(); i++) {
        //     for (int j = 0; j < nums2.size(); j++) {
        //         if (results.size() > 0 && nums1[i] != results[results.size() - 1]) {
        //             if (nums1[i] == nums2[j]) {
        //                 results.push_back(nums1[i]);
        //                 break;
        //             }
                    
        //         }
        //         else if (results.size() == 0 && nums1[i] == nums2[j]) {
        //             results.push_back(nums1[i]);
        //             break;
        //         }
        //     }
        // }

        
    

        return results;
     
    }

    // method1 loop through both vectors and compare, if same add, but check before adding O(n^3)

    // method 2 sort vectors first, and count from bottom, add if not the last digit O(n^2)
    // method 3 hash table, insert into table, if exists, add to vector, should be O(n+m)
    // method 4 sort, one array, and binary search from numbers

};
// @lc code=end

