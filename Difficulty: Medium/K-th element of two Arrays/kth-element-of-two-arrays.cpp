class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i=0,j=0;
        int cnt=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                cnt++;
                if(cnt==k){
                    return a[i];
                }
                i++;
            }else{
                cnt++;
                if(cnt==k){
                    return b[j];
                }
                j++;
            }
        }
        while(i<a.size()){
            cnt++;
            if(cnt==k){
                    return a[i];
                }
            i++;
        }
        while(j<b.size()){
            cnt++;
            if(cnt==k){
                    return b[j];
                }
            j++;
        }
    }
};