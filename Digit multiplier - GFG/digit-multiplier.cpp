//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string getSmallest(long long N) {
        // code here
        if(N<10)
            return to_string(N);
            
        string result="";
        
        while(N!=1){
            if(N%9==0){
                result= "9"+result;
                N= N/9;
            }
            else if(N%8==0){
                result= "8"+result;
                N= N/8;
            }
            else if(N%7==0){
                result= "7"+result;
                N= N/7;
            }
            else if(N%6==0){
                result= "6"+result;
                N= N/6;
            }
            else if(N%5==0){
                result= "5"+result;
                N= N/5;
            }
            else if(N%4==0){
                result= "4"+result;
                N= N/4;
            }
            else if(N%3==0){
                result= "3"+result;
                N= N/3;
            }
            else if(N%2==0){
                result= "2"+result;
                N= N/2;
            }
            else{
                return "-1";
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.getSmallest(N) << endl;
    }
    return 0;
}
// } Driver Code Ends