class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i=0;
        while(i<word.size()){
            char ch = word[i];
            int count = 0;
            while(i<word.size() and word[i]==ch and count<9){
                i++;
                count++;
            }
            ans += to_string(count)+ch;
        }
        return ans;
    }
};