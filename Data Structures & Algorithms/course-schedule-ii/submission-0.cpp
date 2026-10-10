class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indgree(numCourses);
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int src=prerequisites[i][0];
            int tar=prerequisites[i][1];
            adj[tar].push_back(src);
            indgree[src]++;
        }
        queue<int>qe;
        for(int i=0;i<numCourses;i++){
            if(indgree[i]==0)qe.push(i);
        }
        vector<int>ans;
        while(!qe.empty()){
            auto node =qe.front();
            qe.pop();
            ans.push_back(node);

            for(auto nei:adj[node]){
                indgree[nei]--;
                if(indgree[nei]==0)qe.push(nei);
            }
        }
        if (numCourses == ans.size()) {
            return ans;
        } else {
            return {};
        }

    }
};
