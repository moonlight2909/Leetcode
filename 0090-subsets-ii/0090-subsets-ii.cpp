class Solution {
public:
    void helper(vector<vector<int>>& finalans,vector<int>& v,vector<int>& nums,int idx){
        finalans.push_back(v);
        // if(idx==nums.size()){
        //     finalans.push_back(v);
        //     return ;
        // }
        for(int i=idx;i<nums.size();i++){
            if(i!=idx&&nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            helper(finalans,v,nums,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> finalans;
        vector<int> v;
        helper(finalans,v,nums,0);
        return finalans;
    }
};