#include <vector>


// #Hint: No need to go through any stacks.
//        No need to push all the element into min-stack.
//        Use stack build-in pop() & push() to save time.


class MinStack {
public:
    void push(int x) {
        s.push(x);
        if(m.size() == 0 || x <= m.top()){
            m.push(x);
        }
        return;
    }

    void pop() {
        if(s.top() == m.top()){
            s.pop();
            m.pop();
        }
        else{
            s.pop();
        }
        return;
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return m.top();
    }
    
private:
    stack<int> s;
    stack<int> m;
};