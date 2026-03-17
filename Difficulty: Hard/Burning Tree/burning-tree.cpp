class Solution {
  public:
    unordered_map<int, vector<int>> graph;

    void buildGraph(Node* root) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            int u = curr->data;

            if (curr->left) {
                int v = curr->left->data;
                graph[u].push_back(v);
                graph[v].push_back(u);
                q.push(curr->left);
            }
            if (curr->right) {
                int v = curr->right->data;
                graph[u].push_back(v);
                graph[v].push_back(u);
                q.push(curr->right);
            }
        }
    }

    int minTime(Node* root, int target) {
    buildGraph(root);

    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, target});

    int maxTime = 0;

    while (!pq.empty()) {
        pair<int, int> current = pq.top(); pq.pop();
        int time = current.first;
        int node = current.second;

        if (visited.count(node)) continue;
        visited.insert(node);

        maxTime = max(maxTime, time);

        for (int neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                pq.push({time + 1, neighbor});
            }
        }
    }

    return maxTime;
}

};
