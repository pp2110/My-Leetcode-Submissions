class Solution {
public:
    int minBitFlips(int start, int goal) {
        int _xor = start ^ goal;
        
        int count = 0;
        while(_xor != 0){
            int rsbm = (_xor) & (-_xor);
            
            if(rsbm == 0)
                break;
            
            _xor = _xor - rsbm;
            
            count++;
        }
        
        return count;
    }
};