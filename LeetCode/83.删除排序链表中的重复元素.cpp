/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* currentNode = head;
        while(currentNode != nullptr && currentNode->next != nullptr) {
            // if this node val equals next node val, unlink next node
            if(currentNode->val == currentNode->next->val) {
                currentNode->next = currentNode->next->next;
                // currentNode = currentNode->next;
            }
            else currentNode = currentNode->next;
        }
        return head;
    }
};
// @lc code=end

