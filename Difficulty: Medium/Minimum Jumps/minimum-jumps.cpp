//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,vector<int>& arr,vector<int>& dp){
        if (i >= arr.size() - 1) return 0;  // If we reach or exceed last index, no jumps needed.
        if (arr[i] == 0) return INT_MAX / 2;;  // If stuck at a zero, return a large number (infinity).
        if(dp[i]!=-1) return dp[i];
        int result = INT_MAX;
        for (int idx = i + 1; idx <= i + arr[i] && idx < arr.size(); idx++) {
            result = min(result, 1 + solve(idx, arr, dp));
        }
        return dp[i]=result;
    }
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> dp(n,-1);
        int ans = solve(0, arr, dp);
        return (ans >= INT_MAX / 2) ? -1 : ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends