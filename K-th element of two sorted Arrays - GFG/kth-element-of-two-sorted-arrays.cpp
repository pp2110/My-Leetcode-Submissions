//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m < n){
            return kthElement(arr2, arr1, m, n, k);
        }
        
        int start = max(0, k-m), end = min(k, n);
        
        while(start <= end){
            int mid1 = start + (end - start)/2;
            int mid2 = k - mid1;
            
            int left1 = (mid1 == 0)?INT_MIN : arr1[mid1 - 1];
            int left2 = (mid2 == 0)?INT_MIN : arr2[mid2 - 1];
            int right1 = (mid1 == n)?INT_MAX : arr1[mid1];
            int right2 = (mid2 == m)?INT_MAX : arr2[mid2];
            
            if(left1 <= right2 and left2 <= right1){
                return max(left1, left2);
            }
            else if(left1 > right2){
                end = mid1 - 1;
            }
            else 
                start = mid1 + 1;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends