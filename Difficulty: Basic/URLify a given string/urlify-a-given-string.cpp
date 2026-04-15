class Solution {
  public:
    string URLify(string &s) {
        // code here
        string ans="";
        for(auto i:s){
            if(i==' '){
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};