class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
       
         long long int s = 1 , e = *max_element(v.begin() , v.end());
      
         long long int ans = INT_MAX;
        while(s <= e){
                
             long long int mid = (s + e )/2;
            
            // lets say mid is the speed 
            
            //  traverse array
             long long int time = 0;
             long long int ind = 0;
           
            while(ind < v.size()){

              if(v[ind] < mid) time++;
                else if(v[ind]%mid==0) time = time + v[ind]/mid;
                else time = time + v[ind]/mid + 1;
                
                
                ind++;
            }
            
            if(time <= h) ans = min(ans , mid) , e = mid-1;
            else s = mid+1;
            
        }
        
        return ans;
    }
};