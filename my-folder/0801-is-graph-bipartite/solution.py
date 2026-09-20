class Solution:
    def isBipartite(self, graph: list[list[int]]) -> bool:
        """
        start dfs on a given node
        assign it a color
        then assign all its adjacent nodes a different color
        continue with adjacemtn cells, alternating between two colors
        if we ever come across a node who is assigned the same color as one of its neighbors, return false
        else, return true

        biggest mistakes:
        - did not consider disconnected graphs (isolated nodes)
        - redundant visited array wasn't necessary as we have a colors array
        - need to base node coloring on bfs parent, not on a global layer-level
        """

        n = len(graph)

        colors = [-1] * n

        for start in range(n):
            if colors[start] != -1:
                continue
            
            colors[start] = 0
            queue = deque()
            queue.append(start)

            while len(queue) > 0:
                layer_size = len(queue)
                for node_idx in range(layer_size):
                    node = queue.popleft()
                    for neighbor in graph[node]:
                        if colors[neighbor] != -1:
                            if colors[neighbor] == colors[node]:
                                return False
                        else:
                            colors[neighbor] = (colors[node] + 1) % 2
                            queue.append(neighbor)
        
        return True
