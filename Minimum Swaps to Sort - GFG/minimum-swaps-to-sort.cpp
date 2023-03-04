//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<pair<int, int>> vec;
	    
	    for(int i=0; i<n; i++){
	        vec.push_back({nums[i], i});
	    }
	    
	    sort(vec.begin(), vec.end());
	    
	    vector<bool> visited(n, false);
	    int ans = 0;
	    for(int i=0; i<n; i++){
	        if(visited[i] or vec[i].second == i)
	            continue;
	            
	           int size = 0;
	           int j = i;
	           while(!visited[j]){
	               visited[j] = true;
	               j = vec[j].second;
	               size++;
	           }
	           
	           if(size > 0){
	               ans += (size - 1);
	           }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends