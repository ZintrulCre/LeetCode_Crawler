class Solution {
public:
    bool canFinish(int n, vector<pair<int, int>> &prerequisites) {
        vector<unordered_set<int>> graph(n, unordered_set<int>());
        vector<int> in_degree(n, 0);
        for (int i = 0; i < prerequisites.size(); ++i)
            graph[prerequisites[i].second].insert(prerequisites[i].first);
        for (int i = 0; i < n; ++i)
            for (auto in:graph[i])
                ++in_degree[in];
        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (j < n) {
                if (in_degree[j] == 0)
                    break;
                ++j;
            }
            if (j == n)
                return false;
            in_degree[j] = -1;
            for (auto &post:graph[j]) {
                --in_degree[post];
            }
        }
        return true;
    }
};