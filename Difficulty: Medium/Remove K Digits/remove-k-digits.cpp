class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        string ans;
        for(int i=0;i<s.size();i++){
            while(ans.size() != 0 && ans.back() > s[i] && k>0){
                ans.pop_back();
                k--;
            }
            ans += s[i];
        }
        
        while(ans.size() != 0 && k > 0){
            ans.pop_back();
            k--;
        }
        
        int cnt = 0;
        for(auto ch : ans){
            if(ch-'0' == 0) cnt++;
            else break;
        }
        
        if(cnt == ans.size() ) return "0";
        
        return ans.substr(cnt,ans.size());
    }
};