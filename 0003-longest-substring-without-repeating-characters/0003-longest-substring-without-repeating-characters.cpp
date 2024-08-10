class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlength = 0;
        unordered_set<char> st;
        int left = 0;
        for(int i=0;i<n;i++){
            while(st.count(s[i])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            maxlength=max(maxlength,i-left+1);
        }
        return maxlength;
    }
};