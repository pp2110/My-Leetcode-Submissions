//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    pair<vector<int>, vector<int>> findTasks(int *arr, int m, int n) {
        // code here
        pair<vector<int>, vector<int>> ans;
        
        unordered_map<int, int> mp;
        for(int i=0; i<m; i++){
            mp[arr[i]]++;
        }
        
        vector<int> one, two;
        for(int i=1; i<=n; i++){
            if(mp.find(i) == mp.end()){
                if(one.size() == two.size())
                    one.push_back(i);
                else
                    two.push_back(i);
            }
        }
        
        ans.first = one;
        ans.second = two;
        
        return {one, two};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        Solution obj;
        auto ans = obj.findTasks(arr, m, n);
        for (auto x: ans.first) {
            cout << x << " ";
        }
        cout << "\n";
        for (auto x: ans.second) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends