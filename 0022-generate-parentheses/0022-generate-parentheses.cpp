class Solution {
public:
    void f(int n, int open, int close, vector<string>& ans, string str) {
        if (close == n) {
            ans.push_back(str);
            return;
        }
        if (open < n) {
            f(n, open + 1, close, ans,str+'(');
        }
        if(close<open){
            f(n,open,close+1,ans,str+')');
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(n, 0, 0, ans, "");
        return ans;
    }
};