class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<long long> pq;
        for(auto ele : nums){
            pq.push(ele);
        }
        while(k>0){
            long long curr = pq.top();
            ans+=curr;
            pq.pop();
            pq.push(ceil(curr/3.0));
            k--;
        }
        return ans;
    }
};