//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int idx,vector<int>& arr, int sum,vector<vector<bool>>& dp){
        if(sum==0) return true;
        if(idx==0){return arr[idx]==sum;}
        if(dp[idx][sum]!=false) return dp[idx][sum];
        bool not_take=solve(idx-1,arr,sum,dp);
        bool take=0;
        if(arr[idx]<=sum){
            take=solve(idx-1,arr,sum-arr[idx],dp);
        }
        return dp[idx][sum]=take or not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        // return solve(n-1,arr,sum,dp);
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if (arr[0] <= sum) {
           dp[0][arr[0]] = true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool not_take=dp[i-1][j];
                bool take=0;
                if(arr[i]<=j){
                    take=dp[i-1][j-arr[i]];
                }
                dp[i][j]=take or not_take;
            }
        }
        return dp[n-1][sum];
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