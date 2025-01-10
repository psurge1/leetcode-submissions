class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<bool> visited(numCourses, false);
        
        for (const vector<int>& prereq : prerequisites) {
            adjList[prereq[1]].push_back(prereq[0]);
        }

        return !cycleDetected(adjList, numCourses);
    }

    bool cycleDetected(const vector<vector<int>>& adjList, int numNodes) {
        vector<int> incomingEdges(numNodes, 0);
        for (const vector<int>& node : adjList) {
            for (int edgeNode : node) {
                ++incomingEdges[edgeNode];
            }
        }
        stack<int> rootNodes;
        for (int node = 0; node < numNodes; ++node) {
            if (incomingEdges[node] == 0) {
                rootNodes.push(node);
            }
        }
        int count = 0;
        while (rootNodes.size() != 0) {
            ++count;
            int rootNode = rootNodes.top();
            rootNodes.pop();

            for (int edgeNode : adjList[rootNode]) {
                if (--incomingEdges[edgeNode] == 0){
                    rootNodes.push(edgeNode);
                }
            }
        }

        return count != numNodes;
    }
};
