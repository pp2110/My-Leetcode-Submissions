//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    vector<int> smallestSubsegment(int arr[], int n)
    {
    	// Complete the function
    	unordered_map<int,int> freq, sp;
    	
    	int href = 0;
    	int si = 0;
    	int ei = 0;
    	int len = ei - si + 1;
    	
    	for(int i=0; i<n; i++){
    	    if(sp.find(arr[i]) != sp.end()){
    	        freq[arr[i]]++;
    	    }
    	    else{
        	    freq[arr[i]]++;
        	    sp[arr[i]] = i;
    	    }
    	    
    	    if(freq[arr[i]] > href){
    	        href = freq[arr[i]];
    	        si = sp[arr[i]];
    	        ei = i;
    	        len = ei - si + 1;
    	    }
    	    else if(freq[arr[i]] == href){
    	        int c_len = i - sp[arr[i]] + 1;
    	        if(c_len < len){
    	            href = freq[arr[i]];
        	        si = sp[arr[i]];
        	        ei = i;
        	        len = ei - si + 1;
    	        }
    	    }
    	    
    	    
    	}
    	
    	vector<int> ans;
    	
    	for(int i = si; i <= ei; i++){
    	    ans.push_back(arr[i]);
    	}
    	
    	return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    vector<int > v;
	    Solution ob;
	    v = ob.smallestSubsegment(a, n);
	    for(int i:v)
	        cout<< i << " ";
	    cout<<"\n";
	}
return 0;
}

// } Driver Code Ends