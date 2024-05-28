//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
       int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
       int targetSum = (totalSum + d) / 2;
        if (totalSum < d || (totalSum + d) % 2 != 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, 0));
        int mod = 1e9+7;
        
        // Base case: There's one way to make sum 0 (empty subset)
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= targetSum; ++j) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]])%mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][targetSum];
        // Code here
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends