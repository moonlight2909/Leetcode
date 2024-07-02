class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());
        int n = str.size();
        string ans ;
        int i =0;
        int j =0;
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