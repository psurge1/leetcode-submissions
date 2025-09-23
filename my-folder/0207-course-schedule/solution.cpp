class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
            ++indegree[prereq[1]];
        }

        deque<int> dq;
        for (int course = 0; course < numCourses; ++course) {
            if (indegree[course] == 0)
                dq.emplace_back(course);
        }

        vector<int> ordering;
        while (!dq.empty()) {
            int course = dq.front();
            dq.pop_front();
            ordering.push_back(course);

            for (int edgeNode : adjList[course]) {
                --indegree[edgeNode];
                if (indegree[edgeNode] == 0)
                    dq.push_back(edgeNode);
            }
        }

        return ordering.size() == numCourses;
    }
};
