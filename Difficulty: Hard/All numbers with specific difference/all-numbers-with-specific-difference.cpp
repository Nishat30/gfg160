class Solution {
  public:
    int getCount(int n, int d) {
        // code here
        if(d >= n) return 0;
       
        int l = 10, r = n;
        int num = n+1;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            
            int cnt = mid;
            int sum = 0;
            
            while(cnt>0){
                sum += cnt%10;
                cnt = cnt/10;
            }
            
            if((mid-sum) >= d){
                num = mid;
                r = mid-1;
            }
            else  l = mid+1;
            
        }
        
        return n-num+1;
    }
};