class Solution {
public:
    void f(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,int idx){
        ans.push_back(temp);
        for(int i=idx;i<nums.size();i++){
            if(i!=idx and nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            f(ans,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(ans,temp,nums,0);
        return ans;
    }
};