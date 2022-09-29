class Solution {
public:
    
    void dfs(int node, vector<int> adj[], vector<bool> &visited){
        
        visited[node] = true;
        
        for(auto iter : adj[node]){
            if(!visited[iter])
                dfs(iter, adj, visited);
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < (n-1))
            return -1;
        
        vector<int> adj[n];
        
        for(auto iter : connections){
            adj[iter[0]].push_back(iter[1]);
            adj[iter[1]].push_back(iter[0]);
        }
        
        vector<bool> visited(n, false);
        
        int count = 0; 
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }
        
        
        return count-1;
        
        
        
    }
};