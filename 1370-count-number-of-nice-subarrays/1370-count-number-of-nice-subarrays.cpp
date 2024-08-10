class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int oddCount = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1; 

        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) {
                oddCount++;
            }
            if (mp.find(oddCount - k) != mp.end()) {
                ans += mp[oddCount - k];
            }
            mp[oddCount]++;
        }
        
        return ans;
    }
};
