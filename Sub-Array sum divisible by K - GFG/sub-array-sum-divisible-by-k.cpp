//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long k){
	    // Your code goes here
	    unordered_map<int, int> mp;
	    
	    long long sum = 0;
	    long long count = 0;
	    
	    for(int i=0; i<N; i++){
	        sum += arr[i];
	        long long rem = sum % k;
	        if(rem < 0)
	            rem += k;
	           
	        if(sum % k == 0){
	            count++;
	        }
	        if(mp.find(rem) != mp.end())
	            count += mp[rem];
	            
	            mp[rem]++;
	    }
	    
	    return count;
	}



};


//{ Driver Code Starts.

int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends