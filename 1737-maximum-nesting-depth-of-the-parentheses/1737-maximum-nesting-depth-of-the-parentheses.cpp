class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int count = 0;
        int maxi = 0;
        for(auto ele : s){
            if(ele == '('){
                count++;
                if(maxi<count){
                    maxi = count;
                }
            }
            else if(ele ==')'){
                count--;
            }
        }
        return maxi;
    }
};