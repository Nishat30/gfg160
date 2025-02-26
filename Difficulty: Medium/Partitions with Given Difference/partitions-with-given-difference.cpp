//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    const int mod=1e9+7;
    int solve(int idx, int d,vector<vector<int>>& dp,vector<int>& arr){
        if(idx==0){
            if(d==0 && arr[0]==0)return 2;
            if(d==0 || d==arr[0]) return 1;
            return 0;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];
        int not_take=solve(idx-1,d,dp,arr);
        int take=0;
        if(arr[idx]<=d){
            take=solve(idx-1,d-arr[idx],dp,arr);}
        return dp[idx][d]=(take+not_take)%mod;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return solve(n-1,target,dp,arr);
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n=arr.size();
        int total_sum=0;
        for(auto&it:arr)total_sum+=it;
        if(total_sum-d<0 || (total_sum-d)%2) return 0;
        return perfectSum(arr,(total_sum-d)/2);
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends