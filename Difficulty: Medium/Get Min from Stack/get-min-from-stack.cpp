//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    stack<pair<int, int>> st; 
    int curr_min;
  public:
    Solution() {
        // code here
        curr_min = INT_MAX;
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        curr_min = min(curr_min, x);
        st.push(make_pair(x, curr_min));
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if (st.empty()) return;
        st.pop();
        if (!st.empty()) {
            curr_min = st.top().second;
        } else {
            curr_min = INT_MAX;
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if (st.empty()) return -1;
        return st.top().first;
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if (st.empty()) return -1;
        return st.top().second;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends