class Solution {
public:
    void dfs(int i, vector<int>& out, vector<int> adj[], vector<bool>& vis) {
        out.push_back(i);

        for (auto node : adj[i]) {
            if (!vis[node]) {
                vis[node] = true;
                dfs(node, out, adj, vis);
            }
        }
    }

    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int> out;
        vector<bool> vis(v, false);

        vis[0] = true;
        dfs(0, out, adj, vis);

        return out;
    }
};