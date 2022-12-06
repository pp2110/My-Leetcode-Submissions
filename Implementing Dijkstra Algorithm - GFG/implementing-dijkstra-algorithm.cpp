//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> q;
        vector<int> dist(V+1, 1e9);
        dist[S] = 0;
        q.insert({0, S});
        
        while(!q.empty()){
            auto it = *(q.begin());
            int topNode = it.second;
            int topDist = it.first;
            q.erase(it);
            
            for(auto iter : adj[topNode]){
                int newDist = iter[1];
                int adjNode = iter[0];
                
                if(topDist + newDist < dist[adjNode]){
                    
                    if(dist[adjNode] != 1e9)
                        q.erase({dist[adjNode], adjNode});
                        
                    dist[adjNode] = topDist + newDist;
                    q.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends