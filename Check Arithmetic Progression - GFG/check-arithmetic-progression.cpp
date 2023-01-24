//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    bool checkIsAP(int arr[], int n)
    {
        // code here
        sort(arr, arr+n);
        
        unordered_map<int, int> mp;
        for(int i=1; i<n; i++)
            mp[arr[i] - arr[i-1]]++;
        
        if(mp.size() ==1)
            return true;
            
            
        return false;
        
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
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
         (ob.checkIsAP(arr, n))? (cout << "YES" << endl) :
                       (cout << "NO" << endl);   
    }
 
  return 0;
}

// } Driver Code Ends