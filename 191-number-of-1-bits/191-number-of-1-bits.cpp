class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        
        int count = 0;
        while(n){
            
            uint32_t rsbm = n & (-n);

            if(rsbm == 0)
                break;
            
            n = n - rsbm;
            
            count++;
        }
        
        return count;
    }
};