//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pair<pair<int,int>,int>> q;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int total_time=0;
        int one_cnt=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==2){
                    q.push({{i,j},0});
                }
                if(mat[i][j]==1){
                    one_cnt++;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tm=q.front().second;
            q.pop();
            total_time=max(total_time,tm);
            for(int i=0;i<4;i++){
                int dr=row+drow[i];
                int dc=col+dcol[i];
                if(dr<mat.size() && dr>=0 && dc<mat[0].size() && dc>=0 && mat[dr][dc]==1){
                    q.push({{dr,dc},tm+1});
                    mat[dr][dc] = 2; 
                    one_cnt--;
                }
            }
        }
        if(one_cnt!=0) return -1;
        return total_time;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends