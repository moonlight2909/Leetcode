class Solution {
public:
    void f(vector<vector<int>>&ans ,vector<int>&nums,vector<int>&temp,int idx){
        if(idx==nums.size()){
            ans.push_back(temp);
            return ;
        }
        f(ans,nums,temp,idx+1);
        temp.push_back(nums[idx]);
        f(ans,nums,temp,idx+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        f(ans,nums,temp,0);
        return ans;
    }
};