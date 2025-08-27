class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int k,sum,cnt=0;
        for(int i=0;i<n;i++){
            k=i+2;
            for(int j=i+1;j<(n-1);j++){
                sum=arr[i]+arr[j];
                while((k<n) && (arr[k]<sum)) k++;
                if(k==n){
                    cnt+=((n-j-1)*(n-j))/2;
                    break;
                }
                if(k==j) k++;
                cnt+=(k-j-1);
            }
        }
        return cnt;
    }
};
