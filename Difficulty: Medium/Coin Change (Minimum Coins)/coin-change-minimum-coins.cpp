//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int idx,vector<int> &coins, int sum,vector<vector<int>>& dp){
        if(idx<0)return 1e9;
        if(sum==0)return 0;
        
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        int not_take=solve(idx-1,coins,sum,dp);
        int take=1e9;
        if(coins[idx]<=sum){
            take=1+solve(idx,coins,sum-coins[idx],dp);
        }
        return dp[idx][sum]=min(take,not_take);
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        if(solve(n-1,coins,sum,dp)==1e9){return -1;}
        else{return solve(n-1,coins,sum,dp);}
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends