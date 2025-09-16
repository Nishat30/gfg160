class Solution {
  public:
    bool isOperator(string op){
        return (op == "+" || op=="-" || op == "^" || op == "/" || op == "*" );
    }
    int solve(char op , stack<int> &st){
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        int ans = 0;
        switch (op) {
            case '+': ans = first + second;
                break;
            case '*': ans = first * second;
                break;
            case '/': ans=floor((float)second/(float)first);
                break;
            case '-': ans = second - first;
                break;
            case '^': ans = pow(second ,first);
                break;
        }
        return ans;
    }
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int> st;
        for(auto it : arr){
            int value = 0;
            if(isOperator(it)){
                value = solve(it[0] , st);
            }else {
                value = stoi(it);
            }
            st.push(value);
        }
        int result=st.top();st.pop();
        return result;
    }
};