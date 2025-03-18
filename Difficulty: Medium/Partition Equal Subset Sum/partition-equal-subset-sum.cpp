//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int idx,int target,vector<int>& arr,vector<vector<int>>& dp){
        if (target == 0) return true;
        if (idx == 0) return arr[0] == target;
        
        if(dp[idx][target]!=-1) return dp[idx][target];
        
        bool not_take=solve(idx-1,target,arr,dp);
        bool take= false;
        if(arr[idx]<= target){
            take=solve(idx-1,target-arr[idx],arr,dp);
        }
        return dp[idx][target]=take || not_take;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int n=arr.size();
        int total_sum=0;
        for(int i:arr){
            total_sum+=i;
        }
        if(total_sum%2!=0){
            return false;
        }
        int target=total_sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,dp);
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends