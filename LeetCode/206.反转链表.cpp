/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* new_head; 
    ListNode* recursion(ListNode* head) {
        if (head->next == nullptr) {
            new_head = head; // set the new head to be the last of the old head
            return head;
        }
        ListNode* node = recursion(head->next); // return the current head, this is list of all reversed so far
        node->next = head; // add old node to end, next is the one who called recursion
        head->next = nullptr; // set last node's, or node who called this recrsion, to nullptr
        return head;
    
    }
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        // ListNode* curr = head;
        // ListNode* node = new ListNode(curr->val);
        // ListNode* new_head = node;
        // curr = curr->next;
        // while(curr != nullptr) {
        //     node = new ListNode(curr->val);
        //     node->next = new_head;  // previous new head
        //     new_head = node;        // current new node
        //     curr = curr->next;
        // }
        // return new_head;
        recursion(head);
        return new_head;
        // return head;
     
    } 
    // iterative method
};
// @lc code=end

