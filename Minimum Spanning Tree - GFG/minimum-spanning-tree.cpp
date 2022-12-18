//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disJointSet{
    vector<int> parent, rank, size;
    public : 
        disJointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++){
                size[i]= 1;
                parent[i] = i;
            }
        }
        
        int findParent(int u){
            if(u == parent[u])
                return u;
            return parent[u] = findParent(parent[u]);
        }
        
        void uniounByRank(int u, int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            
            if(ulp_u == ulp_v)
                return;
            
            if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else if(rank[ulp_v] > rank[ulp_u]){
                parent[ulp_u] = ulp_v;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
            
        }
        
    
};
class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        
        for(int i=0; i<V; i++){
            for(auto iter : adj[i]){
                int node = i;
                int adjNode = iter[0];
                int weight = iter[1];
                
                edges.push_back({weight, {node, adjNode}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        int mstWeight = 0;
        disJointSet ds(V);
        
        for(auto iter : edges){
            int weight = iter.first;
            int node = iter.second.first;
            int adjNode = iter.second.second;
            
            if(ds.findParent(node) != ds.findParent(adjNode)){
                mstWeight += weight;
                ds.uniounByRank(node, adjNode);
            }
        }
        
        return mstWeight;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends