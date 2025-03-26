//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void solve(string& s, int& ind,vector<string> &dictionary,vector<int>& dp){
        if (ind >= s.size()) return;
        if (dp[ind] != -1) return;
        
        for (int i = 0; i < dictionary.size(); i++) {
            int stringSize = dictionary[i].size();
            int availableSize = s.size() - ind;
            if (
                availableSize >= stringSize &&
                dictionary[i] == s.substr(ind, stringSize)
            ) {
                ind += stringSize;
                solve(s, ind, dictionary, dp);
                if (ind >= s.size()) return;
                ind -= stringSize;
            }
        }
        dp[ind] = 0;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        vector<int> dp(s.size(), -1);
        int ind = 0;
        solve(s, ind, dictionary, dp);
        return ind == s.size();
    }
};


//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends