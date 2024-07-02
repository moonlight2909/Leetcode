class Solution {
public:
    void f(vector<vector<int>>&ans,vector<int>&temp,vector<int> nums,int target,int idx){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(idx==nums.size()){
            return ;
        }
        for(int i=idx;i<nums.size();i++){
            if (nums[i] > target) {
                continue; 
            }
            temp.push_back(nums[i]);
            f(ans,temp,nums,target-nums[i],i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> ans;
        f(ans,temp,nums,target,0);
        return ans;
    }
};