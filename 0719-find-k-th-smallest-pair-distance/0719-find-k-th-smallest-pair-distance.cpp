class Solution {
private:
    bool check(int mid, vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int l = 0, r = 0;
        while (r < n) {
            while (nums[r] - nums[l] > mid) {
                l++;
            }
            cnt += r - l;
            r++;
        }
        return cnt >= k;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0];

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (check(mid, nums, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         int n = nums.size();
//         int left = 0, right = nums[n - 1] - nums[0];
//         sort(nums.begin(),nums.end());

//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             int count = 0;

//             for (int i = 0, j = 0; i < n; i++) {
//                 while (j < n && nums[j] - nums[i] <= mid)
//                     j++;
//                 count += j - i - 1;
//             }

//             if (count < k) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }
//         return left;
//         // vector<int> ans;
//         // int n = nums.size();
//         // priority_queue<int,vector<int>,greater<int>>pq;
//         // for(int i=0;i<n;i++){
//         //     for(int j=i+1;j<n;j++){
//         //         pq.push(abs(nums[i]-nums[j]));
//         //     }
//         // }
//         // for(int i=0;i<k-1;i++){
//         //     pq.pop();

//         // }
//         // return pq.top();
//         // vector<int> ans;
//         // int n = nums.size();
//         // sort(nums.begin(),nums.end());
//         // for(int i=0;i<n;i++){
//         //     for(int j=i+1;j<n;j++){
//         //         ans.push_back(abs(nums[i]-nums[j]));
//         //     }
//         // }
//         // priority_queue<int> pq;
//         // for(auto ele : ans){
//         //     pq.push(ele);
//         // }
//         // while(k!=0){
//         //     pq.pop();
//         //     k--;
//         // }
//         // pq.pop();
//         // int res = pq.top();
//         // return pq.top();
//     }
// };