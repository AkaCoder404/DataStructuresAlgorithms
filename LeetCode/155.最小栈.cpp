/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
struct Node {
    int val;
    int min;
    Node *next;
    Node *prev;
    Node () {
        val = 0;
        min = INT_MAX;
        next = nullptr;
        prev =  nullptr;
    }
    Node (int val, int min) : val(val), min(min), next(nullptr), prev(nullptr) {}
    Node (int val, int min, Node *next, Node *prev) : val(val), min(min), next(next), prev(prev) {}
};


class MinStack {
public:
    Node* current;

    MinStack() {
        current = new Node();
    }
    
    void push(int val) {
        int min = val < current->min ? val : current->min;
        current->next = new Node(val, min, nullptr, current);
        current = current->next;
    }
    
    void pop() {
        current = current->prev;
        current->next = nullptr;
    }
    
    int top() {
        return current->val;
    }
    
    int getMin() {
        return current->min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

