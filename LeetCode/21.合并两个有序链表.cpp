/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // increment, left to right, add the smaller number to the list
        // ListNode* head = new ListNode(0);
        // ListNode* cur = head;
        // while (list1 != nullptr && list2 != nullptr) {
        //     if (list1->val < list2->val) {
        //         cur->next = list1;
        //         list1 = list1->next;
        //     } 
        //     else {
        //         cur->next = list2;
        //         list2 = list2->next;
        //     }
        //     cur = cur->next;
        // }
        // // remaining
        // cur->next = list1 ? list1 : list2;
        // return head->next; 

        // recursion, pass backwards pointer to larger number and set it as the next 
        if(list1 == nullptr) return list2; // return last value of list2
        if(list2 == nullptr) return list1; // return last value of list1
        if(list1->val < list2->val){
            printf("list1->next, list2\n");
            list1->next = mergeTwoLists(list1->next,list2); 
            return list1;
        }
        else{
            printf("list1, list2->next\n");
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};
// @lc code=end

