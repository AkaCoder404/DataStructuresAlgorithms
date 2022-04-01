/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        // method1 
        // ListNode* current = head;
        // std::vector<int> results;
        // while(current != nullptr) {
        //     results.push_back(current->val);
        //     current = current->next;
        // }

        // for (int i = 0; i < results.size() / 2; i++) {
        //     if (results[i] != results[results.size() - 1 - i]) return false;
        // }
        
        // return true;

        // method1
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        // find midpoint
        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next; // 2x faster
        }

        while (slow) {
            ListNode* temp = slow->next;
            slow->next = prev;  // set the next ndoe to be the prev node
            prev = slow;    // save current node to be previous node
            slow = temp;    // update current head of reverse
        }

        while (prev != nullptr && head != nullptr) {
            if (prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }

        return true;
    }
};
// @lc code=end

