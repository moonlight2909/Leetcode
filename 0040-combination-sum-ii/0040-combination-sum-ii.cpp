class Solution {
public:
    void f(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,int target,int idx){
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx and nums[i]==nums[i-1]){
                continue;
            }
            if(target<nums[i]){
                break;
            }
            temp.push_back(nums[i]);
            f(ans,temp,nums,target-nums[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int> temp;
        f(ans,temp,nums,target,0);
        return ans;
    }
};