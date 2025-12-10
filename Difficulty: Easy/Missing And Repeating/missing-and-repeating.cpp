class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int total_sum=0;
        unordered_map<int,int> mp;
        int sum=0;
        for(int i:arr){
            mp[i]++;
            sum+=i;
        }
        int repeat=0;
        for(int i=1;i<=arr.size();i++){
            if(mp[i]>1){
                repeat=i;
            }
            total_sum+=i;
        }
        sum=sum-repeat;
        int miss=total_sum-sum;
        return {repeat,miss};
    }
};