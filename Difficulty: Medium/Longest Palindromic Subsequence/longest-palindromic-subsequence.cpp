//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int n=s1.size();
        int m=s2.size();
        //tabulation 

        //step 1:- base case
        //to make it simplier we will shift base case from idx1<0 to idx1==0
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for (int j=0;j<m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
                }else{
                dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);}
            }
        } 
        return dp[n][m];
    }
    int longestPalinSubseq(string &s) {
        // code here
        string s2=s;
        reverse(s2.begin(),s2.end());
        return lcs(s,s2);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends