//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 0;
    void dfs(int node, int parent, vector<int> &vis, int tim[], int low[], vector<int> &mark, vector<int> adj[]){
        vis[node] = 1;
        low[node] = tim[node] = timer;
        timer++;
        int child = 0;
        
        for(auto iter : adj[node]){
            if(iter == parent)
                continue;
            if(!vis[iter]){
                dfs(iter, node, vis, tim, low, mark, adj);
                low[node] = min(low[iter], low[node]);
                if(low[iter] >= tim[node] and parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node], low[iter]);
            }
        }
        
        if(child > 1 and parent == -1)
            mark[node] = 1;
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> vis(V, 0);
        int low[V], tim[V];
        vector<int> mark(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, vis, tim, low, mark, adj);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(mark[i] == 1)
                ans.push_back(i);
        }
        
        if(ans.size() == 0){
            return {-1};
        }
        
        return ans;
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
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends