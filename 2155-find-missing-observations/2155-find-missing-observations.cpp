class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = mean * (n + m);
        int currentSum = accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum = totalSum - currentSum;
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }
        vector<int> result(n, 1);
        missingSum -= n;
        for (int i = 0; i < n && missingSum > 0; ++i) {
            int add =min(5, missingSum); 
            result[i] += add;
            missingSum -= add;
        }

        return result;
    }
};