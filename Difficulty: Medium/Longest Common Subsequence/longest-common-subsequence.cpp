//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

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
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends