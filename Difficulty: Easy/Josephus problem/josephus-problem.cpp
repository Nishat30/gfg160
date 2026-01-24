class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        int res = 0;  // 0-based
    
    for (int i = 1; i <= n; i++) {
        res = (res + k) % i;
    }
    
    return res + 1;
    }
};