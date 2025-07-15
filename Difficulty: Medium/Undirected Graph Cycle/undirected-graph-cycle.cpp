class Solution {
  public:
    bool bfs(int i,vector<int> adj[],vector<bool>& visited){
        queue<pair<int,int>> q;
        q.push({i,-1});
        visited[i]=true;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(int nbr:adj[node]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push({nbr,node});
                }else{
                    if(parent!=nbr){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]); // build adjacency list
        }
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};