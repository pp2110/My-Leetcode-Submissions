class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int qs = queries.size();
        
        vector<int> prefix_xor(n);
        prefix_xor[0] = arr[0];
        
        for(int i=1; i<n; i++){
            prefix_xor[i] = prefix_xor[i-1]^arr[i];
        }
        
        
        vector<int> ans(qs);
        for(int i=0; i<qs; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            
            if(l == 0){
                ans[i] = prefix_xor[r];
            }
            else
                ans[i] = prefix_xor[l-1]^prefix_xor[r];
        }
        
        return ans;
    }
};