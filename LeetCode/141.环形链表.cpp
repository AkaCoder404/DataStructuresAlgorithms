/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && slow != nullptr) {
            slow = slow->next;
            fast = fast->next == nullptr? fast->next : fast->next->next;
            if (fast == slow && fast != nullptr) return true;
        }
        return false;
    }
};
// @lc code=end

