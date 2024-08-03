class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto ele : target) {
            mp[ele]++;
        }
        for (auto ele : arr) {
            if (mp.count(ele) == 0) {
                return false;
            }
            mp[ele]--;
            if (mp[ele] == 0) {
                mp.erase(ele);
            }
        }
        return mp.size()==0;
        //     using observation
        //     unordered_set<int> st,st2;
        //     for(auto ele : target){
        //         st.insert(ele);
        //     }
        //     for(auto ele : arr){
        //         st2.insert(ele);
        //     }
        //     unordered_map<int,int> mp;
        //     for(auto ele : st){
        //         mp[ele]++;
        //     }
        //     for(auto ele : st2){
        //         mp[ele]++;
        //     }
        //     for(auto ele : mp){
        //         if(ele.second==1){
        //             return false;
        //         }
        //         else {
        //             continue;
        //         }
        //     }
        //     return true;
        // }
    }
};