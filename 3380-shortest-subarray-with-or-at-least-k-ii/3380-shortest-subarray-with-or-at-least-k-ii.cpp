class Solution {
public:
    void incrementBitCounts(vector<int>& bitCounts, int num) {
        int index = 0;
        while (num > 0) {
            int remainder = num % 2;
            if (remainder == 1) {
                bitCounts[index] += 1;
            }
            num = num / 2;
            index++;
        }
    }
    void decrementBitCounts(vector<int>& bitCounts, int num) {
        int index = 0;
        while (num > 0) {
            int remainder = num % 2;
            if (remainder == 1) {
                bitCounts[index] -= 1;
            }
            num = num / 2;
            index++;
        }
    }
    int formNumber(const vector<int>& bitCounts) {
        int value = 0;
        int multiplier = 1;
        for (int i = 0; i < 30; i++) {
            if (bitCounts[i] >= 1) {
                value += multiplier;
            }
            multiplier *= 2;
        }
        return value;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitCounts(32, 0);
        int left = 0, right = 0; 
        int bitwiseOr = 0; 
        int minLength = INT_MAX; 
        for (right = 0; right < nums.size(); right++) {
            bitwiseOr |= nums[right];
            incrementBitCounts(bitCounts, nums[right]); 
            while (left <= right && bitwiseOr >= k) {
                minLength = min(minLength, right - left + 1); 
                decrementBitCounts(bitCounts, nums[left]);
                bitwiseOr = formNumber(bitCounts); 
                left++; 
            }
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};
