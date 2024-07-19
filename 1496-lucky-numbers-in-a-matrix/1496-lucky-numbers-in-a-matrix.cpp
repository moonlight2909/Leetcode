class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> luckyNumbers;
        vector<int> rowMin(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }
        vector<int> colMax(m, INT_MIN);
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }
        
        return luckyNumbers;
    }
};
