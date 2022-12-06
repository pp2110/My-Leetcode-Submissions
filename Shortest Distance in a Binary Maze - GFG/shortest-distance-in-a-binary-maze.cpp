//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(grid[source.first][source.second] == 0)
            return -1;
            
        if(grid[destination.first][destination.second] == 0)
            return -1;
            
        if(source.first == destination.first and source.second == destination.second)
            return 0;
            
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        q.push({0, {source.first, source.second}});
        
        dist[source.first][source.second] = 0;
        
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            auto row = q.front().second.first;
            auto col = q.front().second.second;
            auto dis = q.front().first;
            
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol] == 1 and (dis + 1)<dist[nrow][ncol]){
                    dist[nrow][ncol] = 1 + dis;
                    if(nrow == destination.first and ncol == destination.second)
                        return dis+1;
                    q.push({dis+1, {nrow, ncol}});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends