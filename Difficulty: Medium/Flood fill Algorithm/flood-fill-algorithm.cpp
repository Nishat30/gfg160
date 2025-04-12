//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size();
        int m = image[0].size();
        
        int og = image[sr][sc];
        
        queue<pair<int,int>> q;
        set<pair<int,int>> vis;
        
        q.push({sr,sc});
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int x = it.first;
            int y = it.second;
            
            if(vis.find({x,y})!=vis.end()) continue;
            
            image[x][y] = newColor;
            
            vis.insert({x,y});
    
            
            for(int i=0;i<4;i++){
                int r = x + dx[i];
                int c = y + dy[i];
                
                if(r>=0 && r<n && c>=0 && c<m && image[r][c]==og && vis.find({r,c})==vis.end()){
                    q.push({r,c});
                }
            }
        
        }
        
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends