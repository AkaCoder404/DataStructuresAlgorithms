r/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
int* method1(int *nums, int numsSize, int target, int* returnSize); // brute force O(n * n)
int* method2(int *nums, int numsSize, int target, int* returnSize); // hashmap


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  return method1(nums, numsSize, target, returnSize);
}

int* method1(int *nums, int numsSize, int target, int* returnSize) {
  int *ans = NULL; 
  for(int i = 0; i < numsSize; i++) {
    for(int j = i + 1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        *returnSize = 2;
        ans = malloc(sizeof(int) * 2);  // array of size 2
        ans[0] = i;
        ans[1] = j;
        return ans;
      }
    }
  }
  *returnSize = 0;
  return ans;
}

// @lc code=end

