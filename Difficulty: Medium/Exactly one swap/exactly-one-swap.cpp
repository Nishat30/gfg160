class Solution {
  public:
    int countStrings(string &s) {
        // code here
        unordered_map<char,int>mp;
        int ans=0;
        mp[s[0]]++;
        int n=s.length();
        bool f=false;
        for(int i=1;i<n;i++){
            ans+=(i-mp[s[i]]);
            mp[s[i]]++;
            
            if(mp[s[i]]==2 && !f){
                f=true;
                ans++;
            }
        }
        return ans;
    }
};
