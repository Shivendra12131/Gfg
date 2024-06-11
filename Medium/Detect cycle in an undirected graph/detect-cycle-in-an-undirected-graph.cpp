//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool detect(int node,vector<int>adj[],vector<int>&vis,int parent){
        vis[node]=1;
        for(auto adjacentnode:adj[node])
        {
            
            if(!vis[adjacentnode])
            {
              if(detect(adjacentnode,adj,vis,node)==true) return true;
               
            }
            else if(parent!=adjacentnode) return true;
        }
        return false;
        
    }  
    public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis,-1)) return true;
                
            }
            
        }
        return false;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends