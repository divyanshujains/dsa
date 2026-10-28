class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {

        visited[node] = 1;

        for (auto v : adj[node]) {

            if (visited[v] == 0) {
                if (dfs(v, adj, visited) == false) {
                    return false;
                }
            }
            else if (visited[v] == 1) {
                return false;
            }
        }

        visited[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            int parent = prerequisites[i][1];
            int child = prerequisites[i][0];

            adj[parent].push_back(child);
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited) == false) {
                    return false;
                }
            }
        }

        return true;
    }
};