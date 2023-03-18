//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        
        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; j++, i++){
                if(g==0){
                    dp[i][j] = arr[j];
                }
                else if(g==1){
                    dp[i][j] = max(arr[i], arr[j]);
                }
                else{
                    int front = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                    int back = arr[j] + min(dp[i][j-2], dp[i+1][j-1]);
                    int val = max(front, back);
                    dp[i][j] = val;
                }
            }
        }
        
        return dp[0][n-1];
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends