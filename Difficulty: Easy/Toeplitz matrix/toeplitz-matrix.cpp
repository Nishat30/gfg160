class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        vector<int> diag(n + m - 1, -1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int idx = i-j+(m-1);
                if(diag[idx] == -1){
                    diag[idx] = mat[i][j];
                }
                else if(diag[idx]!=mat[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};