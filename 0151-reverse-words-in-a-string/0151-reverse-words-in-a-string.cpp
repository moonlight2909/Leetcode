class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        deque<string> dq;
        string word;
        
        for(auto ch : s){
            if(ch == ' '){
                if(!word.empty()){
                    dq.push_front(word);
                    word.clear();
                }
            } else {
                word += ch;
            }
        }
        if(!word.empty()){
            dq.push_front(word);
        }
        
        string result;
        while(!dq.empty()){
            result += dq.front();
            dq.pop_front();
            if(!dq.empty()){
                result += " ";
            }
        }
        
        return result;
    }
};
