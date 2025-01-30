#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<array<int, 2>> st;

    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
            return;
        }

        st.push({val, min(val, st.top()[1])});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top()[0];
    }
    
    int getMin() {
        return st.top()[1];
    }
};
