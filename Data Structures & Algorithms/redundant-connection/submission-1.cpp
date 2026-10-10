class Solution {
public:
//Notice that we aren't asking:

// "Does this graph contain a cycle?"

// Instead, we're asking:

// "Is there already a path between u and v before I add the edge (u, v)?
    
    bool dfs(int node, int target,
             vector<vector<int>>& adj,
             vector<int>& vis) {
        if (node == target) return true;

        vis[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (dfs(nei, target, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<int> vis(n + 1, 0);

            // If a path already connects u and v,
            // adding this edge creates a cycle.
            if (dfs(u, v, adj, vis)) {
                return edge;
            }

            // Otherwise, add this edge to the graph.
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};