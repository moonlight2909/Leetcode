class Solution {
public:
    int minAddToMakeValid(string s) {
        if (s.size() == 0) {
            return 0;
        }
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')' and st.size() == 0) {
                count++;
            } else if (s[i] == ')' and st.top() == '(') {
                st.pop();
            }
        }
        count+=st.size();
        return count;
    }
};