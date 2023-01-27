//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    // your code here
    int n = S.size();
    
    map<char, int> mp;
    for(auto iter : S)
        mp[iter]++;
        
    int count = 0;
    
    for(auto iter : mp){
        if(iter.second % 2 != 0)
            count++;
    }
    
    if(count > 1)
        return false;
        
    return true;
}