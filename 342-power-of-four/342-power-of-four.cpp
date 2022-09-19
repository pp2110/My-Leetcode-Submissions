class Solution {
public:
    bool isPowerOfFour(int n) {
        int fact = 0b0101010101010101010101010101010101;
        
        return n>0 && (n&(n-1)) == 0 && ((fact&n) > 0);
    }
};