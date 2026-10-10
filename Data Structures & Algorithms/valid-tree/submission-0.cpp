class Solution {
public:
    // Grap valid tree- 1. Acyclic ; 2. Connected
    bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,int parent){
        vis[node]=1;
        for(auto nei:adj[node]){
            if(nei==parent)continue;
            if(vis[nei])return false;
            if(!dfs(nei,adj,vis,node))return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree with n nodes must have exactly n-1 edges
        if (edges.size() != n - 1) return false;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int src=edges[i][0];
            int tar=edges[i][1];
            adj[src].push_back(tar);
            adj[tar].push_back(src);

        }
         // Check for cycles
        if (!dfs(0, adj, vis,-1)) return false;

        // concentivity check
        for(int i=0;i<n;i++){
            if(vis[i]==0)return false;
        }
        return true;
    }
};
