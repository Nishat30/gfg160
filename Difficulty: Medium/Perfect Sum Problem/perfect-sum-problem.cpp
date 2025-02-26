//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int idx, int d,vector<vector<int>>& dp,vector<int>& arr){
        if (idx == 0) {
            if(d==0 && arr[0]==0) return 2;
            if(d==0 || d==arr[0]) return 1;
            return 0;
        } 
        if(dp[idx][d]!=-1) return dp[idx][d];
        int not_take=solve(idx-1,d,dp,arr);
        int take=0;
        if(arr[idx]<=d){
            take=solve(idx-1,d-arr[idx],dp,arr);}
        return dp[idx][d]=take+not_take;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return solve(n-1,target,dp,arr);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends