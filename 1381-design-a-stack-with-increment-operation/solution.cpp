// 35 ms | 37.6 MB
class CustomStack {
public:
    stack<int>st1;
    stack<int>st2;
    int maxSize;

    CustomStack(int maxSize) {
        this->maxSize=maxSize;

    }
    
    void push(int x) {
        if(st1.size()<maxSize)
        st1.push(x);
        
    }
    
    int pop() {
        if(st1.empty())
        return -1;
        else
        {
            int element=st1.top();
            st1.pop();
            return element;
        }
        
    }
    
    void increment(int k, int val) {
        if(st1.size()<k)
        {
            while(!st1.empty())
            {
            st2.push(st1.top()+val);
            st1.pop();
            }
        }

        else
        {
            int count = st1.size() - k; 
            while(count) 
            { 
             st2.push(st1.top());
             st1.pop(); 
             count--; 
            }

            while(!st1.empty())
            {
              st2.push(st1.top()+val);
              st1.pop();
            
            }
        
        }

        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */