class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int ans=0;
        int temp=0;
        int i=0,j=arr.size()-1;
        while(i<j){
            int h=min(arr[i],arr[j]);
            int b=j-i;
            temp=h*b;
            ans=max(ans,temp);
            if(arr[i]>arr[j]){
                --j;
            }else{
                ++i;
            }
        }
        return ans;
    }
};
