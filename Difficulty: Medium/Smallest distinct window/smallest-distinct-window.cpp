//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set<char>st;
        for(i:str)
        st.insert(i);
        int k=st.size();
        int i=0,j=0;
        unordered_map<char,int>map;
        int mini=INT_MAX;
        while(j<str.length())
        {
            map[str[j]]++;
            j++;
            while(map.size()==k)
            {
                mini=min(mini,j-i);
              
                map[str[i]]--;
                if(map[str[i]]==0)
                map.erase(str[i]);
                i++;
            }
            
        }
        return mini;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends