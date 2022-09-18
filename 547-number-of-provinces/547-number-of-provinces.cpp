class Solution {
public:
    int ans = 0;
    
    void dfs(int src, vector<bool> &visited, vector<int> adjls[]){
        visited[src] = true;
        for(auto iter : adjls[src]){
            if(!visited[iter])
                dfs(iter, visited, adjls);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        
        vector<bool> visited(n, false);
        
        vector<int> adj[n];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }        
            }
        }
        
        int count = 0;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                count++;
            }
        }
        
        return count;
    }
};