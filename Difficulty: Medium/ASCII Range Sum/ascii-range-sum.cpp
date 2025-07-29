class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        vector<int> ans;
        for(auto& i:mp){
            int firstocc=i.second.front();
            int lastocc=i.second.back();
            if(firstocc==lastocc || lastocc==firstocc+1){
                continue;
            }
            
            int cnt=0;
            for(int i=firstocc+1;i<lastocc;i++){
                cnt += static_cast<int>(s[i]);
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};