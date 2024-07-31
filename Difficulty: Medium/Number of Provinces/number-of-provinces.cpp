//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    void traversal(vector<vector<int>>& adj, int i, vector<int>& vis) {
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int j = 0; j < adj[node].size(); j++) {
                if (adj[node][j] == 1 && !vis[j]) {
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                traversal(adj, i, vis);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends