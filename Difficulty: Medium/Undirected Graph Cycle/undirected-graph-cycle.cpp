//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited){
        vector<int> parent(visited.size(),-1);
        queue<int> q;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto& i:adj[node]){
                if(visited[i]!=true){
                    visited[i]=true;
                    parent[i]=node;
                    q.push(i);
                }else if(visited[i] && parent[node] != i){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i = 0;i< (int)edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(V, false);
    
        for (int i = 0; i < V; i++) { //Check for all components
            if (!visited[i]) {
                if (bfs(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends