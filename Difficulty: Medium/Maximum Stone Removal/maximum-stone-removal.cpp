class Solution {
  public:
    int find_par(vector<int>&par, int x)
    {
        if(par[x] == x)return x;
        return par[x] = find_par(par, par[x]);
    }
    void merge_nodes(vector<int>&par, int x, int y)
    {
        x = find_par(par, x);
        y = find_par(par, y);
        par[x] = y;
    }
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int v = stones.size();
         vector<int>par(v, 0);
         map<int, vector<int>>row, col;
         for(int i = 0; i < v; i++)par[i] = i;
         int node = 0;
         for(auto &stone : stones)
         {
             int i = stone[0], j = stone[1];
             row[i].push_back(node);
             col[j].push_back(node);
             node++;
         }
         for(auto &r : row)
         {
             auto nodes = r.second;
             int node = nodes[0];
             for(auto &next : nodes)
             {
                 merge_nodes(par, node, next);
             }
         }
        for(auto &r : col)
         {
             auto nodes = r.second;
             int node = nodes[0];
             for(auto &next : nodes)
             {
                 merge_nodes(par, node, next);
             }
         }
        for(int i = 0; i < v; i++)par[i] = find_par(par, i);
        int ans = 0;
        set<int>st;
        for(auto &it : par)
        {
            st.insert(it);
        }
        ans = v - st.size();
        
         return ans;
    }
};