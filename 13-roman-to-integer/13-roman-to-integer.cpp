class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> um;
        
        um['I']= 1;
        um['V']= 5;
        um['X']= 10;
        um['L']=50;
        um['C']= 100;
        um['D']= 500;
        um['M']= 1000;
        
        int ans=0;
        
        for(int i=s.size()-1; i>=0; i--){
            
            if(i!=0 && um[s[i-1]]<um[s[i]] ){
                ans= ans+  um[s[i]] - um[s[i-1]]; 
                i--;
                continue;
            }
            
            ans=ans+ um[s[i]];
        }
        
        return ans;
    }
};