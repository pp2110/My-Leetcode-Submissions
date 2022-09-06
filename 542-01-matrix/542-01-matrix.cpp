class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        vector<vector<int>> dist(n, vector<int>(m, 0));
        
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = true;
                    q.push({{i, j}, 0});
                }else{
                    visited[i][j] = false;
                }
            }
        }
        
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;
            
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and visited[nrow][ncol] == false){
                        visited[nrow][ncol] = true;
                        q.push({{nrow, ncol}, steps+1});
                    }
                }
            }
        }
        
        return dist;
    }
};