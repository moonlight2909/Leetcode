class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int m = nums.size();
        int ones = 0;
        for (int i = 0; i < m; ++i) {
            if (nums[i] == 1) {
                ++ones;
            }
        }
        if (ones <= 1) {
            return 0;
        }
        for (int i = 0; i < m; ++i) {
            nums.push_back(nums[i]);
        }
        m = nums.size();
        int left = 0;
        int right = ones - 1;
        int swaps = 0;
        for (int i = left; i <= right; ++i) {
            if (nums[i] == 0) {
                ++swaps;
            }
        }
        int ans = swaps;
        while (right < m - 1) {
            if (nums[++right] == 0) {
                ++swaps;
            }
            if (nums[left++] == 0) {
                --swaps;
            }
            ans = min(ans, swaps);
        }
        return ans;
    }
};