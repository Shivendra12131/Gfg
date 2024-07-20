//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long tdown(int n,vector<long long>&dp)
  {
      int mod=1e9+7;
      if(n<=1) return n;// base case
      // if the value is already present in the memory
      if(dp[n]!=-1) return dp[n];
      return dp[n]=(tdown(n-1,dp)+tdown(n-2,dp))%mod;
      
      
      
  }
    long long int topDown(int n) {
        // code here
        int mod=1e9+7;
        vector<long long>dp(n+1,-1);
        return tdown(n,dp);
        
    }
    long long int bottomUp(int n) {
        vector<long long>dp(n+1,-1);
         int mod=1e9+7;
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%mod;
            
        }
        return dp[n];
        // code here
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends