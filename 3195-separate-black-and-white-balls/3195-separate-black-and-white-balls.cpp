class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        long long n = s.size();
        long long counter = 0;
        for(long long i=0;i<n;i++){
            if(s[i]=='1'){
                counter++;
            }
            else{
                ans+=counter;
            }
        }
        return ans;
    }
};