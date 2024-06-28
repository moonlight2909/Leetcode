class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<long long>> graph(n);
        for(auto ele : roads){
            graph[ele[0]].push_back(ele[1]);
            graph[ele[1]].push_back(ele[0]);
        }
        vector<long long> indegree(n);
        for(long long i=0;i<n;i++){
            for(auto ele : graph[i]){
                indegree[ele]++;
            }
        }
        sort(indegree.begin(),indegree.end());
        long long ans = 0;
        long long val = 1;
        for(auto ele : indegree){
            ans += ele*val;
            val++;
        }
        return ans;
    }
};