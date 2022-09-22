class Solution {
public:
    
    
    int helper(int i, int j, vector<vector<bool>> &visited, vector<vector<int>> &grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j] == 0 or visited[i][j] == 1)
            return 0;
        
        visited[i][j] = true;
        
        return (1 + helper(i+1, j, visited, grid) + helper(i-1, j, visited, grid) + helper(i, j+1, visited, grid) + helper(i, j-1, visited, grid));
    }
    

    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] and grid[i][j] == 1){
                    int count = helper(i, j, visited, grid);
                    ans = max(ans, count);
                    
                }
            }
        }
        
        if(ans == INT_MIN)
            return 0;
        
        return ans;
    }
};