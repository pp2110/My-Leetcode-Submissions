class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        
        while(num != 0){
            if(num % 2 == 0){
                num = num / 2;
                
            }
            
            else if(num == 2){
                ans+=2;
                break;
            }
            else{
                num = num - 1;
            }
            
            ans++;
        }
        
        return ans;
    }
};