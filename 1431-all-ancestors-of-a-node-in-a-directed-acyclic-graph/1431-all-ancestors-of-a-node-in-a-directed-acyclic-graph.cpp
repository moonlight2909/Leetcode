class Solution {
public:
    void dfs(vector<vector<int>> &graph, int i, int j, vector<vector<int>> &ans, unordered_set<int> &visited) {
        visited.insert(j);
        for (auto ele : graph[j]) {
            if (visited.count(ele) == 0) {
                ans[ele].push_back(i);
                dfs(graph, i, ele, ans, visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto ele : edges) {
            graph[ele[0]].push_back(ele[1]);
        }
        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            unordered_set<int> visited;
            dfs(graph, i, i, ans, visited);
        }
        return ans;
    }
};
