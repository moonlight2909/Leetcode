class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int zerocount = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == 0) {
                zerocount++;
            }

            while (zerocount > k) {
                if (nums[i] == 0) {
                    zerocount--;
                }
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};