//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int helper(int n, int k, vector<vector<int>>& dp){
        if(k == 0 || k == 1) return k;
        if(n == 1) return k;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int mn = INT_MAX, low = 0, high = k, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            int left = helper(n-1, mid-1, dp);
            int right = helper(n, k-mid, dp);
            
            temp = 1 + max(left, right);
            
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;
    
            mn = min(mn, temp);
        }
        return dp[n][k] = mn;
    }
    
    int eggDrop(int n, int k) 
    {
        
        //k means number of eggs, n means number of floors
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return helper(n, k, dp);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends