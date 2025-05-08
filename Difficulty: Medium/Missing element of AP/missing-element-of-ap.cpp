//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int diff = INT_MAX;
        int n = arr.size();
        for(int i = 1; i< arr.size();i++){
            diff = min(diff,abs(arr[i] - arr[i-1]));
        }
        if(n >= 2 && arr[1] < arr[0])
        diff *= -1;
        
        for(int i = 0; i< arr.size()-1;i++){
            if(arr[i+1] - arr[i]  != diff)
            return arr[i] + diff;
        }
        return arr[n-1] + diff;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends