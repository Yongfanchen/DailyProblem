#include <iostream>
#include <queue>

using namespace std;
class MyStack {
public:
    queue<int> q;
    MyStack() {

    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);
        for(int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int r = q.front();
        q.pop();
        return r;
    }
    
    int top() {
        int r =q.front();
        return r;
    }
    
    bool empty() {
        return q.empty();

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