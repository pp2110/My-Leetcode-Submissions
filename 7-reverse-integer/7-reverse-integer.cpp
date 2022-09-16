class Solution {
public:
    int reverse(int x) {
        int temp = abs(x);
        
        int ans = 0;
        while(temp){
            int a = temp % 10;
            
            temp = temp/10;
            if (ans > INT_MAX/10 || (ans == INT_MAX / 10 && a > 7)) return 0;
            if (ans < INT_MIN/10 || (ans == INT_MIN / 10 && a < -8)) return 0;
            ans = ans*10 + a;
        }
        
        if(x < 0)
            return -ans;
        
        return ans;
    }
};