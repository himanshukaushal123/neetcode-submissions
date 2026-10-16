class Solution {
public:
     vector<string> ans;
     unordered_map<string,multiset<string>>adj;

     void dfs(string airport) {
        while (!adj[airport].empty()) {
            string next = *adj[airport].begin();

            adj[airport].erase(adj[airport].begin());

            dfs(next);
        }

        ans.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //create adjency lsit
        for(auto &ticket:tickets){
            adj[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());

        return ans;

    }
};
