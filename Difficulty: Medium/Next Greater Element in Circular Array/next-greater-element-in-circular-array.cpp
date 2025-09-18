class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n=arr.size();
        stack<int> st;

        vector<int> v(n,-1);
        int i=2*n-1;
        
        while(i>=0){
            int idx= i>=n?i-n:i;
            
            while(st.size() and st.top()<=arr[idx]) st.pop();
            
            if(!st.empty() && i<n) v[i]=st.top();
            
            st.push(arr[idx]);

            i--;
        }
        
        return v;
    }
};