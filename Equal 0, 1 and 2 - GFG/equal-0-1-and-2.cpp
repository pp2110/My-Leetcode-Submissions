//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        int n = str.size();
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        int delta10 = count1 - count0;
        int delta21 = count2 - count1;
        string key = to_string(delta10) + "#" + to_string(delta21);
        int ans = 0;
        
        unordered_map<string, int> mp;
        mp.emplace(key, 1);
        for(int i=0; i<n; i++){
            if(str[i] == '0')   
                count0++;
            else if(str[i] == '1')
                count1++;
            else
                count2++;
                
            delta10 = count1 - count0;
            delta21 = count2 - count1;
            
            key = to_string(delta10) + "#" + to_string(delta21);
            
            if(mp.find(key) != mp.end()){
                ans += mp[key];
                mp[key]++;
            }
            else{
                mp[key]++;
            }
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends