class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        int p=0;
        
        for(auto it:s){
            if(it==')'){
                if(p and st.top()=='(') return 1;
                int ct=0;
                while(st.size() and st.top()!='(') ct++,st.pop();
                if(ct==1) return 1;
                st.pop();
                p=1;
            }
            else {
                st.push(it);
                p=0;
            }
        }
        
        return 0;
    }
};
