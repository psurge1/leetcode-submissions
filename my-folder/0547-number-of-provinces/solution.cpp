class Solution {
public:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int edgeNode : adj[node]) {
            if (!visited[edgeNode]) {
                dfs(edgeNode, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int numNodes = isConnected.size();
        vector<vector<int>> adj(numNodes);
        for (int node = 0; node < numNodes; ++node) {
            for (int edgeNode = node + 1; edgeNode < numNodes; ++edgeNode) {
                if (isConnected[node][edgeNode]) {
                    adj[node].emplace_back(edgeNode);
                    adj[edgeNode].emplace_back(node);
                }
            }
        }

        int numProvinces = 0;
        vector<bool> visited(numNodes, false);
        for (int node = 0; node < numNodes; ++node) {
            if (!visited[node]) {
                ++numProvinces;
                dfs(node, adj, visited);
            }
        }

        return numProvinces;
    }
};
