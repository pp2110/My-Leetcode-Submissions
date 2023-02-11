//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    
    void dfs(int node, vector<bool> &visited, vector<int> adj[], int &count){
        visited[node] = true;
        for(auto iter : adj[node]){
            if(!visited[iter]){
                count++;
                dfs(iter, visited, adj, count);
            }
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    
	    for(int i=0; i<V; i++){
	        int count = 0;
	        vector<bool> visited(V+1, false);
	        dfs(i, visited, adj, count);
	        if(count == V-1)
	            return i;
	    }
	    
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends