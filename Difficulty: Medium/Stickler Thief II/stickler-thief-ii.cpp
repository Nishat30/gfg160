//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int idx,vector<int>& arr,vector<int>& dp){
        if(idx<0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int not_take=solve(idx-1,arr,dp);
        int take=arr[idx] + solve(idx-2,arr,dp);
        return dp[idx]=max(take,not_take);
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        vector<int> dp(n,-1);
        if (n == 1) return arr[0]; 

        vector<int> dp1(n, -1), dp2(n, -1);
        
        vector<int> arr1(arr.begin(), arr.end() - 1);
        int res1 = solve(arr1.size() - 1, arr1, dp1);

        vector<int> arr2(arr.begin() + 1, arr.end());
        int res2 = solve(arr2.size() - 1, arr2, dp2);

        return max(res1, res2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends