//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int dist=i[2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        set<pair<int,int>> st;
        
        vector<int> dist(V,1e9);
        
        dist[src]=0;
        st.insert({0,src});
        
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            
            for(auto it:adj[node]){
                int edgeWeight=it.second;
                int adjNode=it.first;
                
                if(dis+edgeWeight < dist[adjNode]){
                    //erase if existed
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]=dis+edgeWeight;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends