//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void segregateEvenOdd(int nums[], int n) {
	    // code here
        int i=0;
        int j=0;

        while(i < n){
            if(nums[i]%2==0){
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        sort(nums, nums+j);
        sort(nums+j, nums+n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregateEvenOdd(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends