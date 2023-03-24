//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void combine(vector<string> &v, string temp){
        for(int i=0; i<v.size(); i++){
            v[i] += (" "+temp);
        }
    }

    vector<string> helper(string s, unordered_set<string> &st, unordered_map<string, vector<string>> &mp){
        if(mp.find(s) != mp.end()){
            return mp[s];
        }

        vector<string> result;
        if(st.find(s) != st.end()){
            result.push_back(s);
        }

        for(int i=0; i<s.size(); i++){
            string rem = s.substr(i);
            if(st.find(rem) != st.end()){
                vector<string> temp = helper(s.substr(0, i), st, mp);
                combine(temp, rem);
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }

        mp[s] = result;

        return result;
    }


    vector<string> wordBreak(int n, vector<string>& wordDict, string s)
    {
        // code here
        unordered_map<string, vector<string>> mp;
        unordered_set<string> st;
        // int n = wordDict.size();

        for(auto iter : wordDict){
            st.insert(iter);
        }

        return helper(s, st, mp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends