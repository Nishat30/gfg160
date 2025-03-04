//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void findAllLCS(string a, string b, int i, int j, vector<vector<int>> dp, 
    string current, set<string>& result, map<string, set<string>> &memo){
        if(i==0 || j==0){
            reverse(current.begin(), current.end());
            result.insert(current);
            return;
        };
        
        string key = to_string(i)+"_"+to_string(j)+"_"+current;
        if(memo.find(key)!=memo.end()){
            result.insert(memo[key].begin(), memo[key].end());
            return;
        }
        
        set<string> localResult;
        
        if(a[i-1]==b[j-1]){
            current.push_back(a[i-1]);
            findAllLCS(a,b,i-1,j-1,dp,current, localResult, memo);
            current.pop_back();
        }else{
            if (dp[i-1][j] == dp[i][j]) {
                findAllLCS(a, b, i-1, j, dp, current, localResult, memo);
            }
            if (dp[i][j-1] == dp[i][j]) {
                findAllLCS(a, b, i, j-1, dp, current, localResult, memo);
            }
        }
        
        memo[key] = localResult;
        result.insert(localResult.begin(), localResult.end());
        
    }
  
    vector<string> all_longest_common_subsequences(string a, string b) {
        int m = a.length(), n = b.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        set<string> result;
        string current="";
        map<string,set<string>> memo;
        
        findAllLCS(a,b,m,n,dp,current,result, memo);
        return vector<string>(result.begin(), result.end());
    }
};



//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends