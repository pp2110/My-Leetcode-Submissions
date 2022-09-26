class Solution {
public:
   
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int dr[], int dc[]){
        
        int n = grid.size();
        
        queue<pair<int, int>> q;
        int flag  = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    visited[i][j] = true;
                    grid[i][j] = 2;
                    q.push({i, j});
                    flag = 1;
                    break;
                }
                
            }
            if(flag)
                break;
        }
        
        
        while(!q.empty()){
            
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and !visited[nrow][ncol] and grid[nrow][ncol] == 1){
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = 2;
                    visited[nrow][ncol] = true;
                }
            }
        }
        
    }
    
    int bfs_second(vector<vector<int>>& grid, vector<vector<bool>>& visited, int dr[], int dc[]){
        
        int n = grid.size();
        
        queue<vector<int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        
       
        
        while(!q.empty()){
            int row = q.front()[0];
            int col = q.front()[1];
            int count = q.front()[2];
            
            q.pop();
            
            
            
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and !visited[nrow][ncol]){
                    if(grid[nrow][ncol] == 0){
                        visited[nrow][ncol] = true;
                        grid[nrow][ncol] = 1;
                        q.push({nrow, ncol, count+1});
                    }
                    else if(grid[nrow][ncol] == 1){
                        visited[nrow][ncol] = true;
                        q.push({nrow, ncol, count});
                    }else{
                        return count;
                    }
                } 
            }
        }
        
        return -2;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        
        bfs(grid, visited, dr, dc);
        
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j] = false;
            }
        }
        
        return bfs_second(grid, visited, dr, dc);
        
        
        
    }
};