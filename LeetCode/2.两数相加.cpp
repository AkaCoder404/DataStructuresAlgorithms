/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* head = result;
    
        int sum = l1->val + l2->val; 
        int carry = sum / 10;
        result->val = sum % 10;
        
        l1 = l1->next;
        l2 = l2->next;
        // both still have elements left
        while(l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val  + carry; 
            result->next = new ListNode(sum % 10, nullptr); 
            carry = sum / 10;
            
            result = result->next;
            l1 = l1->next;
            l2 = l2->next; 
        }

        // while l1 still has elements left
        while(l1 != nullptr) {
            sum = l1->val + carry;
            carry = sum / 10;
            result->next = new ListNode(sum % 10, nullptr);
            l1 = l1->next;
            result = result->next;
        }
        
        // while l2 still has elements left
        while(l2 != nullptr) {
            sum = l2->val + carry;
            carry = sum / 10;
            result->next = new ListNode(sum % 10, nullptr);
            l2 = l2->next;
            result = result->next;
        }

        if (carry > 0) result->next = new ListNode(carry);
        return head;
    }

     // brute force method O(n);
    ListNode* method1(ListNode *l1, ListNode* l2) {
        return new ListNode(0);
    }


};
// @lc code=end

