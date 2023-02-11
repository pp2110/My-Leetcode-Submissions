//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    
	    vector<vector<int>> dp(n, vector<int>(n,1e9));
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++){
	            if(i == j)
	                dp[i][j] = 0;
	           else if(matrix[i][j] != -1)
	            dp[i][j] = matrix[i][j];
	        }
	    }
	    
	    
	    
	    
	        for(int j = 0; j<n; j++){
	            for(int i = 0; i<n; i++){
	                for(int k = 0; k<n; k++){
	                dp[i][k] = min(dp[i][k], dp[i][j] + dp[j][k]);
	            }
	        }
	    }
	    
	    
	    matrix = dp;
	    
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++)
	            if(matrix[i][j] == 1e9)
	                matrix[i][j] = -1;
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends