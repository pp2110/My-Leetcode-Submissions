class Solution {
public:
    
    int helper(vector<vector<int>> &grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0])
            return -1;
        
        
        queue<pair<pair<int, int>, int>> q;
        
       
        if(grid[0][0] == 0)
            q.push({{0, 0}, 1});
        
        while(!q.empty()){
            
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            
            if(row == n-1 and col == m-1)
                return steps;
            
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    
                    int nrow = row+i;
                    int ncol = col+j;
                    
                    if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol] == 0){
                        
                        grid[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, steps+1});
                        
                    }
                    
                }
            }
            
        }
        
        return -1;
               
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        return helper(grid);
        
    }
};