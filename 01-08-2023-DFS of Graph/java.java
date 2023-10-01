class Solution {
    // Function to return a list containing the DFS traversal of the graph.
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        boolean[] visited = new boolean[V];
        
        // Initialize an ArrayList to store the DFS traversal result
        ArrayList<Integer> dfsTraversal = new ArrayList<>();
        
        // Start DFS from vertex 0 (leftmost vertex)
        dfs(0, adj, visited, dfsTraversal);
        
        return dfsTraversal;
    }
    
    // Recursive function to perform DFS
    private void dfs(int vertex, ArrayList<ArrayList<Integer>> adj, boolean[] visited, ArrayList<Integer> dfsTraversal) {
        // Mark the current vertex as visited
        visited[vertex] = true;
        
        // Add the current vertex to the DFS traversal result
        dfsTraversal.add(vertex);
        
        // Visit all adjacent vertices of the current vertex
        for (int adjacentVertex : adj.get(vertex)) {
            if (!visited[adjacentVertex]) {
                // If the adjacent vertex is not visited, recursively perform DFS on it
                dfs(adjacentVertex, adj, visited, dfsTraversal);
            }
        }
    }
}