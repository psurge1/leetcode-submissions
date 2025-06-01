class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        /*
        Approach: Construct an adjacency list, run bfs or dfs
        */

        List<List<Integer>> adjList = new ArrayList<>();
        List<Boolean> visited = new ArrayList<>();
        for (int vertex = 0; vertex < n; ++vertex) {
            adjList.add(new LinkedList<>());
            visited.add(false);
        }

        for (int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }

        Stack<Integer> stack = new Stack<>();
        stack.add(source);
        while (!stack.isEmpty()) {
            int vertex = stack.pop();
            if (vertex == destination)
                return true;
            for (int edgeVertex : adjList.get(vertex)) {
                if (!visited.get(edgeVertex)) {
                    visited.set(edgeVertex, true);
                    stack.push(edgeVertex);
                }
            }
        }
        return false;
    }
}
