class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        int n = s.size();
        unordered_map<char, int> freq;
        for(auto x: s){
            freq[x]++;
        }
        if(n%2==0){
            for(int i=0; i<n; i++){
                if(freq[s[i]]%2!=0)
                return false;
            }
            return true;
        }
        else{
            int count = 0;
            for(auto x: freq){
                if(x.second%2!=0) count++;
            }
            if(count==1) return true;
            else return false;
        }
    }
};