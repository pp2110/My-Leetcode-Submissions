class Solution {
public:

    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        
        queue<pair<int, int>> q;
        vector<vector<int>> ans;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
         vector<vector<bool>> visited1(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 or j==0){
                    q.push({i, j});
                    visited[i][j] = true;
                    visited1[i][j] = true;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !visited1[nrow][ncol] and grid[nrow][ncol]>=grid[row][col]){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = true;
                    visited1[nrow][ncol] = true;
                }
                
            }
        }
        
        queue<pair<int, int>> q1;
    
        for(int i = 0;i <n; i++){
            for(int j = 0; j<m; j++)
                visited1[i][j] = false;
        }
       
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==(n-1) or j==(m-1)){
                    if(visited[i][j])
                        ans.push_back({i,j});
                    q1.push({i, j});
                    visited1[i][j] = true;
                }
            }
        }
        
        while(!q1.empty()){
            int row = q1.front().first;
            int col = q1.front().second;
            q1.pop();
            
            
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !visited1[nrow][ncol] and grid[nrow][ncol]>=grid[row][col]){
                    if(visited[nrow][ncol])
                        ans.push_back({nrow,ncol});
                    q1.push({nrow, ncol});
                    visited1[nrow][ncol] = true;
                }
    
            }
        }
        
        return ans;
        
        
        
        
    }
};