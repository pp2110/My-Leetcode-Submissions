//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	bool isValid(int ni, int nj, int n){
        if(ni>=0 and ni<n and nj>=0 and nj<n)
            return true;

        return false;
    }
	double findProb(int n,int row, int column, int k)
	{
	    // Code here
	    vector<vector<double>> curr(n+1, vector<double>(n+1, 0));
        vector<vector<double>> next(n+1, vector<double>(n+1, 0));

        curr[row][column] = 1;

        vector<int> dr = {-2, -1, 1, 2, 2, 1, -1, -2};
        vector<int> dc = {1, 2, 2, 1, -1, -2, -2, -1};

        for(int m=0; m<k; m++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    int ni = 0, nj = 0;
                    if(curr[i][j] != 0){
                        for(int l=0; l<8; l++){
                            ni = i + dr[l];
                            nj = j + dc[l];

                            if(isValid(ni, nj, n)){
                                next[ni][nj] += curr[i][j] / 8.0;
                            }
                        }
                    }
                }
            }
            curr = next;
            for (auto &v: next) {
                fill(v.begin(), v.end(), 0);
            }
        }

        double sum = 0.0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum += curr[i][j];
            }
        }

        return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends