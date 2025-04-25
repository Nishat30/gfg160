//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cnt = 1, ele = arr[0]; // Initialize candidate and count
        
        // First Pass: Find a potential majority candidate
        for(int i = 1; i < n; ++i) {
            if(ele == arr[i]) {
                ++cnt; // Increment count if same as candidate
            } else {
                --cnt; // Decrement count if different
            }
            if(cnt == 0) { // Reset candidate if count drops to zero
                ele = arr[i];
                cnt = 1;
            }
        }
        
        // Second Pass: Verify if the candidate is the majority element
        cnt = 0;
        for(int x : arr) {
            if(x == ele) {
                cnt++; // Count occurrences of the candidate
            }
        }
        
        // Return candidate if it's majority, else -1
        return (cnt > n/2) ? ele : -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends