//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int mod=1e9+7;
    int nCr(int n, int r) {
        // code here
        if(r>n)return 0;
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= r; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
        }
        return dp[n][r]%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends