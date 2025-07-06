class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();

        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());

        priority_queue<tuple<int, int, int>> pq;
        set<pair<int, int>> used;
        pq.emplace(a[0] + b[0], 0, 0);
        used.emplace(0, 0);

        vector<int> ans;
        while (k-- && !pq.empty()) {
            tuple<int, int, int> top = pq.top(); pq.pop();
            int sum = get<0>(top);
            int i = get<1>(top);
            int j = get<2>(top);

            ans.push_back(sum);

            if (i + 1 < n && used.insert({i + 1, j}).second)
                pq.emplace(a[i + 1] + b[j], i + 1, j);
            if (j + 1 < n && used.insert({i, j + 1}).second)
                pq.emplace(a[i] + b[j + 1], i, j + 1);
        }

        return ans;
    }
};