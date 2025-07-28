class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int max_sum=0;
        int n = mat.size();
        int m = mat[0].size();

        vector<int> row_sum(n, 0);
        vector<int> col_sum(m, 0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                row_sum[i]+=mat[i][j];
            }
            max_sum=max(max_sum,row_sum[i]);
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                col_sum[i]+=mat[j][i];
            }
            max_sum=max(max_sum,col_sum[i]);
        }
        int min_col_inc=0;
        int min_row_inc=0;
        for(int i=0;i<row_sum.size();i++){
            if(row_sum[i]<max_sum){
                min_row_inc+=max_sum-row_sum[i];
            }
        }
        for(int i=0;i<col_sum.size();i++){
            if(col_sum[i]<max_sum){
                min_col_inc+=max_sum-col_sum[i];
            }
        }
        return min(min_col_inc,min_row_inc);
    }
};