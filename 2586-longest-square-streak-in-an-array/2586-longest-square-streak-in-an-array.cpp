class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<long long> st(nums.begin(), nums.end());
        int maxi = -1;
        for (auto ele : st) {
            int count = 0;
            while (st.find(ele) != st.end()) {
                count++;
                ele *= ele;
            }
            if (count >= 2) {
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};