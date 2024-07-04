class Solution {
public:
    bool pali(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    void f(vector<vector<string>>&ans , vector<string>&str,string &s ,int idx){
        if(idx==s.size()){
            ans.push_back(str);
        }
        else{
            for(int i=idx;i<s.size();i++){
                if(pali(s,idx,i)){
                    str.push_back(s.substr(idx,i-idx+1));
                    f(ans,str,s,i+1);
                    str.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> str;
        f(ans,str,s,0);
        return ans;
    }
};