// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int c=arr[0].size(),r=arr.size(),mini=1e3+1,p=-1,h=-1;
        for(int i=0;i<r;++i){
            if(arr[i][c-1] == 0) continue;
            for(int j=0;j<c;++j){
                if(arr[i][j]==1){
                    mini=min(j,mini);
                    if(p!=mini) {
                        p=mini;
                        h=i;
                    }
                    break;
                }
            }
        }
        return h;
        
    }
};