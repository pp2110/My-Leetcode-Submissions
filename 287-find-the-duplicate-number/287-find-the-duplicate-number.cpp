class Solution {
public:
    int findDuplicate(vector<int>& v) {
        
        for(int i  = 0;i<v.size();i++){

        v[abs(v[i])] = v[abs(v[i])]*(-1);
           if( v[abs(v[i])] >= 0) return abs(v[i]);
            
            
        }
        return 0;
        
    }
};