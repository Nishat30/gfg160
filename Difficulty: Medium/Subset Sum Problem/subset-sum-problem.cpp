//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool solve(int i,vector<int>& arr,int target,vector<vector<int>> dp){
        if(target==0){return true;}
        if(i==0){return arr[i]==target;}
        if(dp[i][target]!=-1)return dp[i][target];
        bool not_take=solve(i-1,arr,target,dp);
        bool take=false;
        if(target>=arr[i]){
            take=solve(i-1,arr,target-arr[i],dp);}
        return dp[i][target]=take or not_take; 
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        // vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        vector<bool> prev(target + 1, false);
        // return solve(n,arr,target,dp);
        prev[0]=true;
        if (arr[0] <= target) {
           prev[arr[0]] = true;
        }
        for(int i=1;i<n;i++){
            vector<bool>curr(target+1,0);
            curr[0]=true;
            for(int j=1;j<=target;j++){
                bool not_take=prev[j];
                bool take=false;
                if(j>=arr[i]){
                   take=prev[j-arr[i]];
                }
                curr[j]=take or not_take;
            }
            prev=curr;
        }
        return prev[target];
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends