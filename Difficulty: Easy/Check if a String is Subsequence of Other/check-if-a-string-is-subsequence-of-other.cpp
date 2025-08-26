class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int j=0;
        for(char i:s2){
            if(i==s1[j]){
                j++;
            }
        }
        return j==s1.size();
    }
};