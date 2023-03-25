//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    vector<long long int> dp(n, 0);
    long long int currSum = a[0];
    dp[0] = currSum;
    for(long long int i=1; i<n; i++){
        if(currSum > 0){
            currSum += a[i];
        }
        else{
            currSum = a[i];
        }
        
        dp[i] = currSum;
    }
    
    long long int ans = INT_MIN;
    long long int exactK = 0;
    
    for(long long int i=0; i<k; i++){
        exactK += a[i];
    }
    
    ans = max(ans, exactK);
    
    for(long long int i=k; i<n; i++){
        exactK += (a[i] - a[i-k]);
        ans = max(ans, exactK);
        
        long long int moreTK = exactK + dp[i-k];
        ans= max(ans, moreTK);
    }
    
    return ans;
}