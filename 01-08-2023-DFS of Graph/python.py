class Solution:
    #Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, V, adj):
        # code here
        visited=[0]*V
        values=[]
        self.dfs(0,adj,visited,values)
        return values
    def dfs(self,node,adj,visited,values):
        visited[node]=1
        values.append(node)
        for i in adj[node]:
            if visited[i]==0:
                self.dfs(i,adj,visited,values)