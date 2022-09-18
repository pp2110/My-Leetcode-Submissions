class Solution {
public:    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int dr[] = {0, 1, 0, -1};
        int dl[] = {1, 0, -1, 0};
                
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 or i == n-1 or j == 0 or j == m-1){
                    if(grid[i][j] == 1){
                        visited[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
           
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dl[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol] == 1 and !visited[nrow][ncol]){
                    visited[nrow][ncol] = true;
                    
                    q.push({nrow, ncol});
                }
            }
        }
        
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 and !visited[i][j])
                    count++;
            }
        }
        
        return count;
    }
};