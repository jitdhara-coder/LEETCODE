class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<vector<int>>& adj) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjacentnode : adj[node]) {

            if (!vis[adjacentnode]) {
                if (dfs(adjacentnode, vis, pathVis, adj) == true) {
                    return true;
                }
            }
            else if (pathVis[adjacentnode]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

       
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj) == true) {
                    return false;
                }
            }
        }

        return true;
    }
};