class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());
        int n = str.size();
        int i=0;
        int j=0;
        string ans = "";
        while(i<str[0].size() and j<str[n-1].size()){
            if(str[0][i]!=str[n-1][j]){
                break;
            }
            ans+=str[0][i];
            i++;
            j++;
        }
        return ans;
    }
};