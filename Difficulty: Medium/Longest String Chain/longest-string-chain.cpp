//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), comp);
        
        int l = words.size();
        map<string,int> mp;
        int max_length = 1;
        
        for(int i =0; i<l; i++)
        {
            int length = 1;
            for(int j=0; j<words[i].size(); j++)
            {
                string sub = words[i].substr(0,j) + words[i].substr(j+1);
                if(mp.find(sub)!=mp.end())
                {
                    length = max(length,mp[sub]+1);
                }
            }
            mp.insert({words[i],length});
            max_length = max(max_length, length);
            
        }
        return max_length;
    }
    static bool comp(const string &a, const string &b){
        return a.size()<b.size();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends