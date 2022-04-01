/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        // keep track of max 
        int nums1_lim = m;
        int j = 0; // keep track of pos of nums1
        int i;     // keeps track of pos of nums2
        for(i = 0; i < n && j < nums1_lim; i++) { // can't exceed length of nums1 and nums2
            if (nums2[i] <= nums1[j]) {
                nums1.insert(nums1.begin() + j, nums2[i]);
                nums1_lim++;
            } 
            else i--;
            j++;   
        }
        // fill leftover values in nums2
        // aka rest of values in nums2 are bigger than biggest num in nums1
        for (; i < n; i++, j++) {
            nums1[j] = nums2[i];
        }

        // pop zeroes
        while (nums1.size() > n + m) nums1.pop_back();
    }

    // O(n + m), start from beggining of nums2, insert in correct location of nums1
    // if nums2 numbers are bigger than all of nums1, insert at end
    // pop extra zeroes 
    void method1() {}


    // start from end, since we know that nums1[] array has enough size
    // compare last value of nums2 with last value of nums1, and insert into last position
    // decrement both pointers, and repeat
    // faster because no need to pop
    void method2() {}

};
// @lc code=end



// [1]\n1\n[]\n0
// [0]\n0\n[1]\n1
// [2,0]\n1\n[1]\n1
// [1,3,5,0,0,0,0]\n3\n[2,4,6,8]\n4