class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> ans;

        for (int i = 0; i < prerequisites.size(); i++) {

            int parent = prerequisites[i][0];
            int child = prerequisites[i][1];
            adj[child].push_back(parent);
            indeg[parent]++;
        }

        queue<int> q;

        for (int i = 0; i < indeg.size(); i++) {

            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {

            int p = q.front();
            q.pop();

            for (auto i : adj[p]) {

                indeg[i]--;

                if (indeg[i] == 0) {
                    q.push(i);
                }
            }

            ans.push_back(p);
        }

        if (ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};