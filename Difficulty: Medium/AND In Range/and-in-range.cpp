class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int ans = l;
        int diff = r-l;
        int bit = 1;
        while(bit<=diff){
            if(ans&bit){
                ans = ans&~(bit);
            }
            bit<<=1;
        }
        return ans&r;
    }
};
