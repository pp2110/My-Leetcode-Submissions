class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        map<int,int> m;
       long long int n=nums.size();
        for(int i=0;i<nums.size();i++){
            ans+=m[nums[i]-i]*1ll;
            m[nums[i]-i]++;
        }
        
        return (n*(n-1))/2 - ans;
    }
};