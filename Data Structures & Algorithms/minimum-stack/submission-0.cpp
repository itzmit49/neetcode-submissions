class MinStack {
public:
stack<int>st;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
       // mn=min(mn,val);
        
    }
    
    void pop() {
        st.pop();

        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        int mn=INT_MAX;
        vector<int>val;
        while(!st.empty()){
            mn=min(mn,st.top());
            val.push_back(st.top());
            st.pop();


        }
        for(int i=val.size()-1;i>=0;i--){
            st.push(val[i]);
        }
        return mn;

        
    }
};
