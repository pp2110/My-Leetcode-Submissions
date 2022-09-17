class Solution {
public:
    vector<int> singleNumber(vector<int>& vec) {
        long long int _xor = 0;
        
        int n = vec.size();
		for(int i=0; i<n; i++){
			_xor = _xor ^ vec[i];
		}

		long long int rsbm = _xor & (-_xor);

		int x = 0, y = 0;
		for(auto iter : vec){
			if((iter & rsbm) == 0){
				x = x ^ iter;
			}
			else{
				y = y ^ iter;
			}
		}
        
        vector<int> ans;
        ans.push_back(x);
        ans.push_back(y);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};