class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numPoints = points.size();
        vector<vector<pair<int, int>>> adj(numPoints);

        for (int point = 0; point < numPoints; ++point) {
            for (int otherPoint = point + 1; otherPoint < numPoints; ++otherPoint) {
                int edgeWeight = abs(points[point][0] - points[otherPoint][0]) + abs(points[point][1] - points[otherPoint][1]);
                adj[point].emplace_back(edgeWeight, otherPoint);
                adj[otherPoint].emplace_back(edgeWeight, point);
            }
        }

        int numNodesInMST = 0;
        int totalCost = 0;
        vector<bool> visited(numPoints, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> hp;
        hp.emplace(0, 0);
        while (numNodesInMST < numPoints && !hp.empty()) {
            const auto [weight, node] = hp.top();
            hp.pop();

            if (visited[node])
                continue;
            visited[node] = true;
            ++numNodesInMST;
            totalCost += weight;

            for (const pair<int, int>& edge: adj[node]) {
                hp.emplace(edge.first, edge.second);
            }
        }

        return totalCost;
    }
};
