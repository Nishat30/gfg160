//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    int evaluate(vector<string>& arr) {
        stack<int> st;
        
        for (string s : arr) {
            if (isOperator(s)) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (s == "+") st.push(a + b);
                if (s == "-") st.push(a - b);
                if (s == "*") st.push(a * b);
                if (s == "/") st.push(a / b); 
            } 
            else {
                st.push(stoi(s));
            }
        }
        
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends