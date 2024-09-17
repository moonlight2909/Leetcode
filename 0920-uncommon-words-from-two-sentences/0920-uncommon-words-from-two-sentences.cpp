class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> hmap(0);
        A = A + " " + B + " "; 
        string s = "";
        for (char c : A) {
            if (c != ' ')
                s.push_back(c);
            else {
                hmap[s]++;
                s = "";
            }
        }
        vector<string> res;
        for (auto it : hmap) {
            if (it.second == 1) {
                res.push_back(it.first);
            }
        }
        return res;
    }
};
