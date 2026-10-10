class Solution {
public:

    // Almost! Let's clarify with your example.

// cpp
// ```
// prerequisites = {{1, 0}};
// ```

// This means course 0 must be completed before course 1.

// For Kahn's algorithm, think of the arrow as:

// text
// ```
// 0 → 1
// ```

// - Course `0` has indegree `0`, so it enters the queue first.
// - You complete course `0` and remove it from the queue.
// - Then you reduce the indegree of course `1`.
// - Course `1` now has indegree `0`, so it enters the queue next.

// Your key rule: When processing a course, decrease the indegree of the courses that depend on it.

// Now look at your adjacency list again: does `adj[src].push_back(tar)` represent this direction, or the opposite direction?
    // 
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
            auto node=qe.front();
            qe.pop();
            ans.push_back(node);
            for(auto nei:adj[node]){
                indgree[nei]--;
                if(indgree[nei]==0)qe.push(nei);
            }
        }

        return ans.size()==numCourses;


    }
};
