//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int solve(int idx,vector<int>& val, vector<int>& wt, int w,vector<vector<int>>& dp){
        if(idx==0){
            return (w/wt[0])*val[0];
        }
        if(dp[idx][w]!=-1)return dp[idx][w];
        int not_take=0+ solve(idx-1,val,wt,w,dp);
        int take=INT_MIN;
        if(wt[idx]<=w){
            take=val[idx]+solve(idx,val,wt,w-wt[idx],dp);
            // infinite supply hai therefore we will stand in same index
        }
        return dp[idx][w]=max(take,not_take);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return solve(n-1,val,wt,capacity,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends