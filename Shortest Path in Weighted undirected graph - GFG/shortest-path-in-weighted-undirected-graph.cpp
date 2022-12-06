//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int, int>> adj[n+1];
        
        for(auto iter : edges){
            adj[iter[0]].push_back({iter[1], iter[2]});
            adj[iter[1]].push_back({iter[0], iter[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        vector<int> dist(n+1, 1e9), parent(n+1);
        for(int i=1; i<=n; i++)
            parent[i] = i;
       
        dist[1] = 0;    
        q.push({0, 1});
        
        while(!q.empty()){
            auto node = q.top().second;
            auto dis = q.top().first;
            q.pop();
            
            for(auto iter : adj[node]){
                auto adjNode = iter.first;
                auto edgeW = iter.second;
                
                if(dist[adjNode] > edgeW + dis){
                    dist[adjNode] = dis + edgeW;
                    parent[adjNode] = node;
                    q.push({dis + edgeW, adjNode});
                }
            }
            
        }
        
        if(dist[n] == 1e9)
            return {-1};
            
        vector<int> path;
        int node = n;
        
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];    
        }
        
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends