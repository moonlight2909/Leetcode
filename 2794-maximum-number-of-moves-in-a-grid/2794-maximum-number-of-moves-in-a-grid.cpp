class Solution {
public:
    int f(vector<vector<int>>& grid,int i ,int j,int prev ,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m ){
            return 0;
        }
        if(prev>=grid[i][j]){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int first = f(grid, i - 1, j + 1, grid[i][j], dp);
        int second = f(grid, i, j + 1, grid[i][j], dp);
        int three = f(grid, i + 1, j + 1, grid[i][j], dp);
        return dp[i][j]=1+max({first,second,three});
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            int curr = f(grid,i,0,0,dp);
            ans = max(ans,curr);
        }
        return ans - 1;

    }
};