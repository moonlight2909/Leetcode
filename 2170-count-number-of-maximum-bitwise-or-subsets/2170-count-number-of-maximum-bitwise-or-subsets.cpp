class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            max = (max | nums[i]);
        }
        unordered_map<int, int> or_bucket;
        or_bucket[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            vector<pair<int, int>> contrib;
            for (auto val : or_bucket) {
                contrib.push_back({val.first | nums[i], val.second});
            }
            while (!contrib.empty()) {
                or_bucket[contrib.back().first] += contrib.back().second;
                contrib.pop_back();
            }
        }
        return or_bucket[max];
    }
};
