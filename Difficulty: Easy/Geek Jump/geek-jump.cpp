//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int solve(vector<int>&height,int index,vector<int>&dp)
    {
         if(index==0) return 0;
        // if(n==1) return height[1];
        if(dp[index]!=-1) return dp[index];
        
        int left=solve(height,index-1,dp)+abs(height[index-1]-height[index]);
        int right=INT_MAX;
        if(index>1){
             right=solve(height,index-2,dp)+abs(height[index-2]-height[index]);
            
        }
        
        return dp[index]=min(left,right);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1,-1);
        return solve(height,n-1,dp);
        // Code here
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends