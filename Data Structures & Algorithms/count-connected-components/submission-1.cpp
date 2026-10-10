class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&vis){
        vis[node]=1;
        for(auto nei:adj[node]){
            if(!vis[nei])dfs(nei,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(int i=0;i<edges.size();i++){
            int src=edges[i][0];
            int tar=edges[i][1];
            adj[src].push_back(tar);
            adj[tar].push_back(src);

        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }
};
