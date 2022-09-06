class Solution {
public:
    long long func(int a){
   long long  int x=0;
        while(a){
            x=x*10+a%10;
            a=a/10;
        }
        return x;
    }
    int countNicePairs(vector<int>& nums) {
        int ans=0;
        map<long long,long long> m;
        int n=nums.size();
        int M=1e9+7;
        for(int i=0;i<nums.size();i++){
            long long a=nums[i];
            ans+=m[ a-func(a) ];
            ans=ans%M;
            m[a-func(a)]++;
        }
        return ans%M;
    }
};