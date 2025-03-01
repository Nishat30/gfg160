//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {\
        stack<int> numStack;
        stack<char> charStack;
        string temp = "";
        string res = "";

        for (int i = 0; i < s.length(); i++) {
           int cnt = 0;
            if (s[i] >= '0' && s[i] <= '9') {
                while (s[i] >= '0' && s[i] <= '9') {
                   cnt = cnt * 10 + s[i] - '0';
                   i++;
                }
                i--;
                numStack.push(cnt);
            }

        // If closing bracket ']' is encountered
        else if (s[i] == ']') {
            temp = "";

            cnt = numStack.top();
            numStack.pop();
            
              // pop element till opening bracket '[' is not found in the
            // character stack.
            while (charStack.top() != '[') {
                temp = charStack.top() + temp;
                charStack.pop();
            }
            charStack.pop();

            // Repeating the popped string 'temp' count number of times.
            for (int j = 0; j < cnt; j++)
                res = res.append(temp);

            // Push it in the character stack.
            for (int j = 0; j < res.length(); j++)
                charStack.push(res[j]);

            res = "";
        }
        else
            charStack.push(s[i]);
    }
    while (!charStack.empty()) {
        res = charStack.top() + res;
        charStack.pop();
    }

    return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends