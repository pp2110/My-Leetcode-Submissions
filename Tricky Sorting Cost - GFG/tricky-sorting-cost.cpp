//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int sortingCost(int N, int arr[]){
        // code here
        unordered_map<int, int> mp;
        mp[arr[0]] = 1;
        
        for(int i=1; i<N; i++){
            if(mp.find(arr[i] - 1) != mp.end())
                mp.emplace(arr[i], mp[arr[i] - 1]+1);
                
            else
                mp.emplace(arr[i], 1);
        }
        int ans = 0;        
        for(auto iter : mp){
            ans = max(ans, iter.second);
        }
        
        return N - ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        Solution ob;
        
        cout<<ob.sortingCost(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends