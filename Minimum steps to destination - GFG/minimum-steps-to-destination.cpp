//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D){
        // code here
        int jumps = 1;
        int current = 0;
        while(current < D){
            current += jumps;
            jumps++;
        }
        
        if((current-D) % 2 == 0){
            return jumps - 1;
        }
        else if((current+jumps-D) % 2 == 0){
            return jumps;
        }
        else{
            return jumps + 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}
// } Driver Code Ends