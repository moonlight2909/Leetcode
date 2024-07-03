class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if (n <= 4) {
            return 0;
        }
        int ans = min({nums[n - 1] - nums[3], nums[n - 2] - nums[2],nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
        return ans;
    }
};
    // class Solution {
    // public:
    //     int minDifference(vector<int>& nums) {
    //         int n = nums.size();
    //         sort(nums.begin(), nums.end());
    //         int mini = nums[0];
    //         int count = 0;

    //         for(int i = n - 1; i >= 0; i--) {
    //             if(count == 3) {
    //                 break;
    //             }
    //             nums[i] = mini;
    //             count++;
    //         }

    //         int maxi = INT_MIN;
    //         int minx = INT_MAX;

    //         for(int i = 0; i < n; i++) {
    //             if(nums[i] > maxi) {
    //                 maxi = nums[i];
    //             }
    //         }

    //         for (int i = 0; i < n; i++) {
    //             if(nums[i] < minx) {
    //                 minx = nums[i];
    //             }
    //         }

    //         int ans = abs(maxi - minx);
    //         return ans;
    //     }
    // };
    // // 0 1 1 4 6 6 6
    // // 0 1 1 4 0 0 0
