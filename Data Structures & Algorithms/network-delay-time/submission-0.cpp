class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
         vector<vector<pair<int,int>>> adj(n + 1);

        // Build adjacency list
        for (auto &t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];

            adj[u].push_back({v, w});
        }
        dist[k] = 0;
        min_heap.push({0,k});
        while(!min_heap.empty()){
            auto[dis,node]=min_heap.top();
            min_heap.pop();
            if(dis>dist[node])continue;
            for(auto nei:adj[node]){
               int val = nei.first;
                int wt = nei.second;
                if(dist[val]>dis+wt){
                    dist[val]=dis+wt;
                    min_heap.push({dis+wt,val});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;

    }
};
