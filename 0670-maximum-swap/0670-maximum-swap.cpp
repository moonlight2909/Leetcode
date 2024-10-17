class Solution {
public:
    int getmax(string s , int i){
        int maxi = i;
        for(int j=i;j<s.size();j++){
            if(s[maxi]<=s[j]){
                maxi=j;
            }
        }
        return maxi;
    }
    int maximumSwap(int num) {
        string s = to_string(num);
        string str = s;
        for(int i=0;i<s.size();i++){
            int temp = getmax(s,i);
            swap(s[i],s[temp]);
            if(str!=s){
                break;
            }
        }
        int ans = stoi(s);
        return ans;
    }
};