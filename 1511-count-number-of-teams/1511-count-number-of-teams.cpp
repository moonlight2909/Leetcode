class Solution {
public:
    int numTeams(vector<int>& rating) {
        int k = count(rating);
        reverse(rating.begin(), rating.end());
        k += count(rating);
        return k;
    }

private:
    int count(vector<int>& rating) {
        int n = rating.size();
        vector<int> greater(n, 0);
        vector<int> smaller(n, 0);

        for (int i = 0; i < n; ++i) {
            int target = rating[i];
            int c = 0;
            for (int j = i + 1; j < n; ++j) {
                if (rating[j] > target)
                    c++;
            }
            greater[i] = c;
        }

        for (int i = 0; i < n; ++i) {
            int target = rating[i];
            int c = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (rating[j] < target)
                    c++;
            }
            smaller[i] = c;
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += greater[i] * smaller[i];
        }

        return sum;
    }
};