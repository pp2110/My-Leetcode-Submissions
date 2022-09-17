class Solution {
public:
    int helper(string& s, int idx) {
        if (idx == 0) return 0;
        
        if (s[idx] == '1') {
            int curr = idx;
            
            while (curr >= 0 && s[curr] == '1') 
                s[curr--] = '0';
            
            if (curr == -1) 
                return (idx+1) + 1;
            
            s[curr] = '1';
            return helper(s, idx) + 1;
        }
        
        return helper(s, idx-1) + 1;
    }
    
    int numSteps(string s) {
       
        
        return helper(s, s.size()-1);
    }
};