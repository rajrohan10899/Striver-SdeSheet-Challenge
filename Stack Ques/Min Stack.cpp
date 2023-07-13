// https://www.codingninjas.com/studio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465

#include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};

































// https://leetcode.com/problems/min-stack/description/

***************************LEETCODE**************************************

class MinStack {
public:
    vector<int> st;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        if(st.size() == 0) return;
        st.pop_back();
    }
    
    int top() {
        if(st.size() == 0) return -1;
        return st.back();
    }
    
    int getMin() {
        if(st.size() == 0) return -1;
        return *min_element(st.begin(), st.end());
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
