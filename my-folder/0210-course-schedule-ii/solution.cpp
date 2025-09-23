class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (const auto& prereq : prerequisites) {
            adj[prereq[0]].push_back(prereq[1]);
            ++indegree[prereq[1]];
        }

        deque<int> dq;
        for (int course = 0; course < numCourses; ++course) {
            if (indegree[course] == 0)
                dq.emplace_back(course);
        }

        vector<int> ordered_list;
        while (!dq.empty()) {
            int course = dq.front();
            dq.pop_front();
            ordered_list.emplace_back(course);

            for (int edgeNode : adj[course]) {
                --indegree[edgeNode];
                if (indegree[edgeNode] == 0)
                    dq.emplace_back(edgeNode);
            }
        }

        if (ordered_list.size() != numCourses)
            return {};
        reverse(ordered_list.begin(), ordered_list.end());
        return ordered_list;
    }
};
