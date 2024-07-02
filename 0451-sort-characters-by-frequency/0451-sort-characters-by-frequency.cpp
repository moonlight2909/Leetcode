class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(auto ele : s){
            mp[ele]++;
        }
        string ans;
        priority_queue<pair<int,char>>pq;
        for(auto ele : mp){
            pq.push({ele.second,ele.first});
        }
        while(!pq.empty()){
            int feq = pq.top().first;
            int ch = pq.top().second;
            pq.pop();
            for(int i=0;i<feq;i++){
                ans+=ch;
            }

        }
        return ans;
    }
};