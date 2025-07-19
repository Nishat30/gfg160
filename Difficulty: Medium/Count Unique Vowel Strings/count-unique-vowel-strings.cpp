class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        map<char,int> mp;
        for(char c:s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ){
                mp[c]++;
            }
        }
        int n=mp.size();
        int ans=n;
        
        for(int i=2;i<n;i++){
            ans*=i;
        }
        for(auto i:mp){
            ans*=i.second;
        }
        return ans;
    }
};