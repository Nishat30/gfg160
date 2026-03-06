class Solution {
  public:
    bool check(unordered_map<int,int>&ms,unordered_map<int,int>&mp){
       if(ms.size()<mp.size())
       return false;
       for(auto it:mp){
           if(it.second>ms[it.first])
           return false;
       }
       return true;
    }
    string minWindow(string &s, string &p) {
        // code here
        unordered_map<int,int>mp;
        for(auto it:p)
        mp[it]++;
        
        string ans="";
        int i=0;
        int j=0;
        unordered_map<int,int>ms;
        while(i<s.size() && j<s.size()){
            ms[s[j]]++;
            while(check(ms,mp) && i<s.size()){
                if(ans=="" || ans.size()>j-i+1)
                ans=s.substr(i,j-i+1);
                ms[s[i]]--;
                if(ms[s[i]]==0)
                ms.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};