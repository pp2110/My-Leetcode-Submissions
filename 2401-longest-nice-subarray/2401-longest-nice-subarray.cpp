class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 1;
        int curr=0;
        
        for(int i=0;i<n;i++){
            
            while(j<n and (curr&nums[i])!=0){
                curr=(curr^nums[j]);
                j++;
            }
            
            curr=(curr|nums[i]);
            ans=max(ans,i-j+1);
            
        }
        return ans;
    }
};