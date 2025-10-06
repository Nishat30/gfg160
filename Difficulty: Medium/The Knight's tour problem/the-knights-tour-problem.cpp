class Solution {
  public:
     bool solve(int i,int j,int step,int n,vector<vector<int>>&ans){
      if(step==n*n){
          return true;
      }
      vector<vector<int>>dir={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
      for(int k=0;k<8;k++){
          int newx=i+dir[k][0];
          int newy=j+dir[k][1];
          if(newx>=0 && newy>=0 && newx<n && newy<n && ans[newx][newy]==-1){
              ans[newx][newy]=step;
              if(solve(newx,newy,step+1,n,ans)){
                  return true;
              }
              ans[newx][newy]=-1;
          }
      }
      return false;
    }
    vector<vector<int>> knightTour(int n) {
        // code here
         vector<vector<int>>ans(n,vector<int>(n,-1));
        ans[0][0]=0;
        if(n==2 || n==3){
            return {};
        }
        if(!solve(0,0,1,n,ans)){
            return {};
        }
        return ans;
    }
};