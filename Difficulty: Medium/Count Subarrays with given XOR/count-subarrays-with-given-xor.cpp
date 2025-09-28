class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int Xor = 0;
        long ans = 0;
        unordered_map<int, int> mp;
        for (int i=0;i<arr.size();i++){
            Xor ^= arr[i];                    
            if (Xor == k)                      
               ans++;
            if (mp.find(Xor^k)!=mp.end()){ 
                ans += mp[Xor ^ k];
            }            
           mp[Xor]++;                        
       }
       return ans;
    }
};
