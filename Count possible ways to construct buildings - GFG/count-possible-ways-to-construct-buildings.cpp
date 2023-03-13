//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod=1e9+7;
	int TotalWays(int n)
	{
	    // Code here
	    vector<long long int> dp0(n+1, 0), dp1(n+1, 0);
	    
	    dp0[1] = 1, dp1[1] = 1;
	    
	    for(int i=2; i<=n; i++){
	        dp1[i] = (dp0[i-1] + dp1[i-1])%mod;
	        dp0[i] = dp1[i-1]%mod;
	    }
	    
	    return ((dp1[n] + dp0[n])*(dp1[n] + dp0[n]))%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends