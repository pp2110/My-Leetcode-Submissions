class Solution {
public:
    int helper(vector<vector<int>>& grid, int dr[], int dc[]){
        int n = grid.size();
        
        
        queue<vector<int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    q.push({i, j, 0});
            }
        }
        
        int ans = -1;
        
        while(!q.empty()){
            int row = q.front()[0];
            int col = q.front()[1];
            int dist = q.front()[2];
            
            ans = max(ans, dist);
            q.pop();
            
            for(int i=0; i<4; i++){
                
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol] == 0){
                    grid[nrow][ncol] = 1;
                    q.push({nrow, ncol, dist+1});
                }
            }
        }
        
        return ans != 0 ? ans : -1;
    }
    
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        
        return helper(grid, dr, dc);
    }
};