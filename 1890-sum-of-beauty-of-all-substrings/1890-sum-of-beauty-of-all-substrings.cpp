class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j = i;j<n;j++){
                mp[s[j]]++;
                int maxi = 0;
                int mini = INT_MAX;
                for(auto ele : mp){
                    maxi = max(maxi,ele.second);
                    mini = min(mini,ele.second);
                }
                sum+=(maxi-mini);
            }
        }
        return sum;
    }
};