class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        sort(items.begin(), items.end());
        vector<pair<int, int>> ans;
        for (int i = 0; i < m; i++) {
            ans.push_back({queries[i], i});
        }
        sort(ans.begin(), ans.end());
        vector<int> res(m);
        int maxBeauty = 0, j = 0;
        for (int i = 0; i < m; i++) {
            int queryPrice = ans[i].first;
            int queryIndex = ans[i].second;
            while (j < n && items[j][0] <= queryPrice) {
                maxBeauty = max(maxBeauty, items[j][1]);
                j++;
            }
            res[queryIndex] = maxBeauty;
        }

        return res;
    }
};
