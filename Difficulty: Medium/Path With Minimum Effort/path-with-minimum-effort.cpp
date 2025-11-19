class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n= mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        
        while(!pq.empty()){
            int cost=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            if(row==n-1 && col==m-1){
                return cost;
            }
            
            if(cost>dist[row][col]) continue;
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int diff=abs(mat[nrow][ncol]-mat[row][col]);
                    int ncost=max(cost,diff);
                    
                    if(ncost<dist[nrow][ncol]){
                        dist[nrow][ncol]= ncost;
                        pq.push({ncost,{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
    }
};
