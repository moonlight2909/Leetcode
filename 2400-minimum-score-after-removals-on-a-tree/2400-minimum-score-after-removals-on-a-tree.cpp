class Solution {
    vector<bool> visited;
    vector<vector<int>> pc, adj; 
    vector<vector<bool>> childs; 
    vector<int> child_xor, nums,par; 

    int dfs(int i) {
        int ans = nums[i];
        visited[i] = true;

        for (int p : par)
            childs[p][i] =
                true; 

        par.push_back(i);

        for (int child : adj[i])
            if (!visited[child]) {
                pc.push_back({i, child});
                ans ^= dfs(child); 
            }

        par.pop_back();

        return child_xor[i] = ans;
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {

        int n = nums.size(), ans = INT_MAX;
        visited = vector<bool>(n);
        pc = vector<vector<int>>();
        adj = vector<vector<int>>(n);
        child_xor = vector<int>(n, 0);
        childs = vector<vector<bool>>(n, vector<bool>(n, false));
        this->nums = nums;
        par = vector<int>();

        for (vector<int>& edge : edges)
            adj[edge[0]].push_back(edge[1]), adj[edge[1]].push_back(edge[0]);

        dfs(0);

        for (int i = 0; i < pc.size(); i++)
            for (int j = i + 1; j < pc.size();
                 j++) { 
                int a = pc[i][1],
                    b = pc[j][1]; 
                int xa = child_xor[a], xb = child_xor[b], xc = child_xor[0];

                if (childs[a][b])
                    xc ^= xa, xa ^= xb;
                else
                    xc ^= xa, xc ^= xb;

                ans = min(max(xa, max(xb, xc)) - min(xa, min(xb, xc)), ans);
            }

        return ans;
    }
};