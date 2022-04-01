/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
struct Node {
    int val;
    Node *next;
    Node *previous;
    Node() {}
    Node(int val) : val(val) {}
    Node(int val, Node* next) : val(val), next(next) {}
};

class MyStack {
public:
    Node* head;
    Node* current;
    MyStack() {
        head = new Node();
        current = head;
    }
    
    void push(int x) {
        current->next = new Node(x);
        current->next->previous = current;
        current = current->next;
    }
    
    int pop() {
        int value = current->val;
        current = current->previous;
        current->next = nullptr;
        return value;
    }
    
    int top() {
        return current->val;
    }
    
    bool empty() {
        return current == head;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

