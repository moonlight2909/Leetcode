class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for(auto ele : s){
            if(ele =='(' and count==0){
                count++;
            }
            else if(ele=='(' and count>=1){
                ans+=ele;
                count++;
            }
            else if(ele==')' and count >1){
                ans+=ele;
                count--;
            }
            else if(ele ==')' and count==1){
                count--;
            }

        }
        return ans;
    }
};