class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int n =s.size();
        int res = 0;     
        for(int i = n-1; i >=0; i--){
            char c = s[i];
            if(!st.empty() && st.top() < c){
                res++;
                st.pop();
            }else{
                st.push(c);
            }
        }
        
        return res;
    }
};