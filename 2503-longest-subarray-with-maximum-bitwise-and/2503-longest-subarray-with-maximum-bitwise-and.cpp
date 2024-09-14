class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi  = *max_element(nums.begin(),nums.end());
        int sub = 0;
        int ans = 1;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                sub++;
                ans = max(ans,sub);
            }
            else{
                sub  = 0;
            }
        }
        return ans;
    }

};