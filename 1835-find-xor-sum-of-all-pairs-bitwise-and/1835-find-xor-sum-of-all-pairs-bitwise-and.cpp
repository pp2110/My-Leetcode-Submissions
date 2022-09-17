class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int _xor = 0, _xor1 = 0;
        
        int n = arr1.size(), m = arr2.size();
        
        for(int i=0; i<n; i++){
            _xor = _xor ^ arr1[i];
        }
        
        for(int i=0; i<m; i++){
            _xor1 = _xor1 ^ arr2[i];
        }
        
        return (_xor1 & _xor);
    }
};