//{ Driver Code Starts
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        // code here
        map<int, int> x_map, y_map;
        map<pair<int, int>, int> pair_map;
        int count = 0;
        for(int i=0; i<N; i++){
            int x_co = X[i];
            int y_co = Y[i];
            
            if(x_map.find(x_co) != x_map.end()){
                count += x_map[x_co];
                x_map[x_co]++;
            }
            else{
                x_map[x_co]++;
            }
            
            if(y_map.find(y_co) != y_map.end()){
                count += y_map[y_co];
                y_map[y_co]++;
            }
            else{
                y_map[y_co]++;
            }
            
            if(pair_map.find({x_co, y_co}) != pair_map.end()){
                count -= 2*pair_map[{x_co, y_co}];
                pair_map[{x_co, y_co}]++;
            }
            else{
                pair_map[{x_co, y_co}]++;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}
// } Driver Code Ends