class Solution {
public:
    int nearestExit(vector<vector<char>>& grid, vector<int>& entrance) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<vector<int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 or i==(n-1) or j==0 or j==(m-1)){
                    if(grid[i][j]=='.' and  (i!=entrance[0] || j!=entrance[1]) and !visited[i][j]){
                        // cout<<i<<" "<<j<<endl;
                        q.push({i, j, 0});
                        visited[i][j] = true;
                    }
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
                
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !visited[nrow][ncol] and grid[nrow][ncol]=='.'){
                    
                    if(nrow == entrance[0] and ncol == entrance[1])
                        return count+1;
                    
                    q.push({nrow, ncol, count+1});
                    visited[nrow][ncol] = true;
                }
            }
        }
        
        return -1;
        
    }
};