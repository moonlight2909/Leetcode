class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int n = nums.size();
        int xo = 0;
        for(auto &ele:nums){
            xo^=ele;
        }
        int mask = pow(2,maximumBit)-1;
        for(int i=n-1;i>=0;i--){
            ans.push_back(xo^mask);
            xo^=nums[i];
        }
        return ans;
    }
};