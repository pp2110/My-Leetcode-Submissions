class Solution {
public:
    
    void helper(int node, int end, vector<vector<int>>& graph, vector<vector<int>> &ans, vector<int> level, vector<bool> &visited){
        
       if(node == end){
           ans.push_back(level);
           return;
       }
        
        
        for(int i=0; i<graph[node].size(); i++){
            
            int curr = graph[node][i];
            
            if(!visited[curr]){
                
                visited[curr] = true;
                
                level.push_back(curr);
            
                helper(curr, end, graph, ans, level, visited);
            
                level.pop_back();
                
                visited[curr] = false;
                
            }
            
            
        }
        
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        
        int n = graph.size();
        
        vector<bool> visited(n, false);
        
        vector<int> level;
        
        level.push_back(0);
        visited[0] = true;
        
        helper(0, n-1, graph, ans, level, visited);
        
        return ans;
        
    }
};