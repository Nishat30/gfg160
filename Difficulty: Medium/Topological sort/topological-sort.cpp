//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node,unordered_map<int,bool>& visited,stack<int>&s,vector<vector<int>>& adj){
        visited[node]=1;
        for(auto i: adj[node]){
            if(!visited[i]){
                dfs(i,visited,s,adj);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto&a:edges){
            adj[a[0]].push_back(a[1]);
        }
        int n=adj.size();
        unordered_map<int,bool> visited;
        stack<int>s;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,s,adj);
            }
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
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