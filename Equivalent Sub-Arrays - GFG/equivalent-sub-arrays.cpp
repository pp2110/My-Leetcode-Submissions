//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        set<int> st;
        for(int i=0; i<n; i++)
            st.insert(arr[i]);
            
        int k = st.size();
        
        unordered_map<int, int> mp;
        
        int ans = 0;
        int i = -1, j = -1;
        
        while(true){
            bool f1 = false, f2 = false;
            
            while(i < n-1){
                f1 = true;
                i++;
                mp[arr[i]]++;
                
                if(mp.size() == k){
                    ans += n - i;
                    break;
                }
            }
            
            while(j < i){
                f2 = true;
                j++;
                if(mp[arr[j]] == 1)
                    mp.erase(arr[j]);
                else
                    mp[arr[j]]--;
                    
                if(mp.size() == k){
                    ans += n - i;
                }
                else
                    break;
            }
            
            if(!f1 and !f2)
                break;
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends