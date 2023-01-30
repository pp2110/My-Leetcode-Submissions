//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(int src, vector<bool> &visited, vector<bool> &dfsVisited, vector<int> adj[]){
        visited[src] = true;
        dfsVisited[src] = true;
        
        for(auto iter : adj[src]){
            if(!visited[iter]){
                if(dfs(iter, visited, dfsVisited, adj))
                    return true;
                
            }else if(dfsVisited[iter])
                return true;
            
        }
        dfsVisited[src] = false;
        
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> visited(V, false);
        vector<bool> dfsVisited(V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, visited, dfsVisited, adj))
                    return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends