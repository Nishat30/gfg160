class Solution {
  public:
    int countSubstr(string& s, int k) {
        // code here.
        int cnt=0;
        for(int i=0;i<s.length();i++){
            vector<int> freq(26,0);
            int dist=0;
            for(int j=i;j<s.length();j++){
                if(freq[s[j]-'a']==0){
                    dist++;
                }
                freq[s[j]-'a']++;
                if(dist==k){
                    cnt++;
                }
                if(dist>k){
                    break;
                }
            }
        }
        return cnt;
    }
};