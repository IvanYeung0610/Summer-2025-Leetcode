// Ivan Yeung
// 155. Min Stack

using namespace std;

struct Node {
    Node* next;
    int val;
    int min;
};

class MinStack {
    Node* head;
public:
    MinStack() : head(nullptr) {
    }
    
    void push(int val) {
        if (head == nullptr || val < head->min) {
            head = new Node{head, val, val};
        } else {
            head = new Node{head, val, head->min};
        }
    }
    
    void pop() {
        Node* temp = head;
        head = temp->next;
        delete temp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};

int main() {}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
