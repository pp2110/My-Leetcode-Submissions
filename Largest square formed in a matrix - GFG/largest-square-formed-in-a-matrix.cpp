//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    

    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = INT_MIN;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 and j == m-1){
                    dp[i][j] = mat[i][j];
                }
                else if(i == n-1){
                    dp[i][j] = mat[i][j];
                }
                else if(j == m-1){
                    dp[i][j] = mat[i][j];
                }
                else{
                    if(mat[i][j] == 0)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1])) + 1;
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends