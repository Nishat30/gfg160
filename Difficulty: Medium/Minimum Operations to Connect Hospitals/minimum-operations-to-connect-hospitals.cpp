class DisjointSet{
  public:
  vector<int> rank,size,parent;
    DisjointSet(int n){
        rank.resize(n,0);
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int FindUPar(int n){
        if(parent[n]==n) return n;
        return parent[n]=FindUPar(parent[n]);
    }
    
    void UnionBySize(int u,int v){
        int up_u=FindUPar(u);
        int up_v=FindUPar(v);
        if(up_u==up_v) return ;
        if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_v] += size[up_u];
        }else{
            parent[up_v]=up_u;
            size[up_u] += size[up_v];
        }
    }
    
    void UnionByRank(int u,int v){
        int up_u=FindUPar(u);
        int up_v=FindUPar(v);
        if(up_u==up_v) return ;
        if(rank[up_u]<rank[up_v]){
            parent[up_u]=up_v;
        }else if(rank[up_v]<rank[up_u]){
            parent[up_v]=up_u;
        }else{
            parent[up_v]=up_u;
            rank[up_u]++;
        }
    }
};
class Solution {
  public:
    
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
         DisjointSet ds(V);
        int Extra=0;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.FindUPar(u)==ds.FindUPar(v)) Extra++;
            else ds.UnionBySize(u,v);
        }
        int comp=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i) comp++;
        }
        
        int ans=comp-1;
        return (Extra>=ans)?ans:-1;
        
    }
};
