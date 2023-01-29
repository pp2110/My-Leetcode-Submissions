//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> nge(n);
        stack<int> st;
        
        st.push(n-1);
        nge[n-1] = n;
        
        for(int i=n-2; i>=0; i--){
            while(!st.empty() and arr[i] >= arr[st.top()]){
                st.pop();
            }
            
            if(st.size() == 0)
                nge[i] = n;
            else
                nge[i] = st.top();
                
            st.push(i);
        }
        
        int j=0;
        vector<int> ans;
        for(int i=0; i<=n-k; i++){
            if(j < i)
                j = i;
            
            while(nge[j] < k + i){
                j = nge[j];
            }    
            ans.push_back(arr[j]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends