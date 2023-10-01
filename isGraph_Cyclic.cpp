#include <bits/stdc++.h>
using namespace std;
// Detect cycle in an undirected graph using BFS traversal

// Function to detect cycle in an undirected graph.
bool detectCycle(int source, vector<int> adj[], vector<bool>& visited){
    // Mark the source vertex as visited
    visited[source] = true;

    // intialize queue for BFS
    // here pair is for (vertex,parent)
    queue<pair<int,int>> q;

    // push source vertex in queue
    q.push({source,-1});
    
    while(!q.empty()){ //traverse till queue is not empty

        int vertex = q.front().first;
        int parent=q.front().second; 
        q.pop();
        
        for(auto neighbor : adj[vertex]){

            if(visited[neighbor] == false){ //if neighbor is not visited then insert in queue and mark it visited
                visited[neighbor]=true;
                q.push({neighbor,vertex});
            }
            else if(parent != neighbor) return true; //if it is visited and also it is not the parent then there exists a cycle
        }
        
    }

    return false;
}

int main() {
        int V = 4;  //No. of vertexes
        int E = 2;  //No. of edges

        // Create adj list 
        vector<int> adj[V] = {{}, {2}, {1, 3}, {2}} ;
        
        // Create visited array
        vector<bool> visited(V,false);


        for(int i=0; i<V; i++) {

            if(visited[i] == false){
                if(detectCycle(i,adj,visited) == true) {
                    cout << "The graph contains a cycle" << endl;
                    return 0;
                }
            }
        }
        cout << "The graph does not contain a cycle" << endl;

    return 0;
}
// } Driver Code Ends