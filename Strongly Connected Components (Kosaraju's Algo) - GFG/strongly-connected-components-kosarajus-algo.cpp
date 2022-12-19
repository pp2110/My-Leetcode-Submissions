//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    void dfs(int src, vector<int> &vis, vector<int> adj[], stack<int> &st){
        vis[src] = 1;
        for(auto iter : adj[src]){
            if(!vis[iter])
                dfs(iter, vis, adj, st);
        }
        st.push(src);
    }
    
    void dfs3(int src, vector<int> &vis, vector<int> adjT[]){
        vis[src] = 1;
        for(auto iter : adjT[src]){
            if(!vis[iter])
                dfs3(iter, vis, adjT);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V+1, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        vector<int> adjT[V+1];
        
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto iter : adj[i]){
                adjT[iter].push_back(i);
            }
        }
        
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        
        return scc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends