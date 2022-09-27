class Solution {
public:
    
    void helper(int node, vector<vector<int>>& rooms, vector<bool> &visited){
        
        visited[node] = true;
        
        for(auto iter : rooms[node]){
            
            if(!visited[iter]){
                
                visited[iter] = true;
                
                helper(iter, rooms, visited);
                
            }
            
        }
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        vector<bool> visited(n, false);
        
        helper(0, rooms, visited);
        
        bool flag = false;
        
        for(auto iter : visited){
            if(iter == false)
                flag = true;
        }
        
        return (flag)?(false):(true);
        
    }
};