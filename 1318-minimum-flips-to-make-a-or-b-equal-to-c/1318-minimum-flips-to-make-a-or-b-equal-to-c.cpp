class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i=0; i<32; i++){
            bool ai = false;
            bool bi = false;
            bool ci = false;
            
            if( (a & (1<<i)) > 0) 
                ai = true;
            if( (b & (1<<i)) > 0) 
                bi = true;
            if( (c & (1<<i)) > 0) 
                ci = true;
            
            if(ci){
                if(!ai and !bi)
                    ans++;
            }
            else{
                if(ai and bi)
                    ans+=2;
                else if(ai or bi)
                    ans++;
            }
        }
        
        return ans;
    }
};